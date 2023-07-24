/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_utils.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 08:56:32 by mfouadi           #+#    #+#             */
/*   Updated: 2023/07/22 17:11:59 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_UTILS_H
# define INTERSECTION_UTILS_H

# include "vectors.h"

typedef struct s_eq2d
{
	double	a;
	double	b;
	double	c;
	double	t1;
	double	t2;
	double	delta;
}	t_eq2d;

#endif // INTERSECTIONS_UTILS_H