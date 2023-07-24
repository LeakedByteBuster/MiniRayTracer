/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rays.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 01:33:54 by absaid            #+#    #+#             */
/*   Updated: 2023/07/22 19:13:36 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// coord = {x, y}
void	ft_ray(t_cam *cam, int coord[2], t_mlx *mlx, t_ray *ray)
{
	double		x_map;
	double		y_map;
	t_vec		up;
	t_vec		side;

	if (!cam || !mlx || !ray)
		return ;
	ray->origin = cam->center;
	x_map = (double)(2 * coord[0]) / WIDTH - 1;
	y_map = (double)(2 * coord[1]) / HEIGHT - 1;
	up = (vecxnum(cam->upvec, mlx->n_height * y_map));
	side = (vecxnum(cam->sidevec, mlx->n_width * x_map));
	ray->direction = normvec(vecadd(cam->forvec, vecadd(up, side)));
}
