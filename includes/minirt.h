/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 07:58:50 by absaid            #+#    #+#             */
/*   Updated: 2023/07/19 12:19:05 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
#define MINIRT_H

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
# define WIDTH 900
# define HEIGHT 800

# define DESTROY	17
# define KEYBOARD	2

#include "camera.h"
#include "cylinder.h"
#include "light.h"
#include "sphere.h"
#include "plane.h"
#include "render.h"
#include "render_utils.h"
// #include "intersection_utils.h"

/* ************************************************************************** */
/*									Enum Struct								  */
/* ************************************************************************** */

enum s_type
{
	LIGHT,
	PLANE,
	CAMERA,
	SPHERE,
	CYLINDER,
	AMBIENT_LIGHT
} t_type;


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
bool	ray_cylinder_intersection(t_utils *utils, t_cylinder *cyl);
void	find_intersections_with_objects(t_data *data, t_utils *utils);
bool  intersp(t_utils *utils, t_sphere *sp);


#ifndef ERROR_MSG
# define ERROR_MSG "ERROR: incorect Input\n"
#endif // FOV_ERROR

#endif
