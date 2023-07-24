/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 07:58:50 by absaid            #+#    #+#             */
/*   Updated: 2023/07/22 17:18:23 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdbool.h>

# include "gc.h"
# include "libft.h"

# define EPS 0.00001
# define WIDTH 800
# define HEIGHT 800

# define DESTROY	17
# define KEYBOARD	2

# include "camera.h"
# include "cylinder.h"
# include "light.h"
# include "sphere.h"
# include "plane.h"
# include "render.h"
# include "render_utils.h"

typedef enum s_type
{
	LIGHT,
	PLANE,
	CAMERA,
	SPHERE,
	CYLINDER,
	AMBIENT_LIGHT
}	t_type;

/* ************************************************************************** */
/*							Linked list of each object						  */
/* ************************************************************************** */

typedef struct s_data
{
	t_cam		*cam;
	t_cylinder	*cyl;
	t_sphere	*sph;
	t_light		*lights;
	t_plane		*pl;
	t_light		*amlight;
}	t_data;

/* ************************************************************************** */
/*								Intersections								  */
/* ************************************************************************** */
void	find_intersections_with_objects(t_data *data, t_utils *utils);
int		checkfile(char *file);
void	initdata(t_data *data);

# ifndef ERROR_MSG
#  define ERROR_MSG "ERROR: incorect Input\n"
# endif // FOV_ERROR

#endif
