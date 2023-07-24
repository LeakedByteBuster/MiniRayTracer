/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:55:32 by absaid            #+#    #+#             */
/*   Updated: 2023/07/22 19:15:00 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "screen.h"

static int	destroy_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}

static int	key_hook_handler(int key, t_mlx *mlx)
{
	if (key == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	return (0);
}

static void	camera_orientation(t_cam *cam)
{
	if (!cam)
		return ;
	cam->forvec = normvec(cam->forvec);
	cam->sidevec = cross_prod((t_vec){0, 1, 0}, cam->forvec);
	if (!cam->sidevec.x && !cam->sidevec.y && !cam->sidevec.z)
		cam->sidevec = cross_prod((t_vec){1, 0, 0}, cam->forvec);
	cam->sidevec = normvec(cam->sidevec);
	cam->upvec = cross_prod(cam->sidevec, cam->forvec);
	cam->upvec = normvec(cam->upvec);
	return ;
}

static void	init_new_size(t_mlx	*mlx, t_data *data)
{
	double	angle;

	if (!data->cam || !mlx)
		return ;
	camera_orientation(data->cam);
	angle = data->cam->fov * M_PI / 180;
	mlx->n_width = tan(angle / 2);
	mlx->n_height = HEIGHT * mlx->n_width / WIDTH;
}

void	rt_rendering(t_data *data, t_utils *utils, t_mlx *mlx)
{
	int	color;
	int	i;
	int	j;

	j = -1;
	init_new_size(mlx, data);
	while (++j < HEIGHT)
	{
		i = -1;
		while (++i < WIDTH)
		{
			utils->t.t = -1;
			utils->t.color = (t_color){0, 0, 0};
			ft_ray(data->cam, (int []){i, j}, mlx, &utils->ray);
			find_intersections_with_objects(data, utils);
			color = (int)(utils->t.color.x) << 16 | \
				(int)utils->t.color.y << 8 | (int)utils->t.color.z;
			put_pixel_on_image(mlx->img, i, j, color);
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img->img, 0, 0);
	mlx_hook(mlx->win, DESTROY, 0, destroy_window, mlx);
	mlx_hook(mlx->win, KEYBOARD, 0, key_hook_handler, mlx->mlx);
	mlx_loop(mlx->mlx);
}
