/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 08:37:15 by mfouadi           #+#    #+#             */
/*   Updated: 2023/07/22 18:23:57 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "vectors.h"
# include <stdbool.h>

typedef struct s_intersection_utils	t_utils;

typedef struct s_sphere
{
	int				type;
	t_point			center;
	double			diam;
	t_color			color;
	struct s_sphere	*next;
}	t_sphere;

bool	intersp(t_utils *utils, t_sphere *sp);

#endif // SPHERE_H