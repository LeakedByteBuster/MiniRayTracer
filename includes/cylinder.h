/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 08:38:43 by mfouadi           #+#    #+#             */
/*   Updated: 2023/07/22 17:10:58 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "vectors.h"
# include <stdbool.h>

typedef struct s_intersection_utils	t_utils;

typedef struct s_cylinder
{
	int					type;
	t_point				center;
	double				diam;
	double				height;
	t_vec				nvec;
	t_color				color;
	struct s_cylinder	*next;
}	t_cylinder;

bool	ray_cylinder_intersection(t_utils *utils, t_cylinder *cyl);

#endif // CYLINDER_H