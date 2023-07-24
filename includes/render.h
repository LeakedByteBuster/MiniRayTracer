/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:29:30 by absaid            #+#    #+#             */
/*   Updated: 2023/07/22 19:14:03 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "minirt.h"
# include "screen.h"
# include "render_utils.h"
# include "light.h"

typedef struct s_data	t_data;
typedef struct s_light	t_light;

typedef struct s_intersection_utils
{
	t_solution	t;
	t_ray		ray;
	t_mlx		mlx;
	t_light		*am;
	t_light		*l;
}	t_utils;

/* ************************************************************************** */
/*								Rendering									  */
/* ************************************************************************** */
void	rt_rendering(t_data *data, t_utils *utils, t_mlx *mlx);
void	ft_ray(t_cam *cam, int coord[2], t_mlx *mlx, t_ray *ray);

#endif // RENDER_H
