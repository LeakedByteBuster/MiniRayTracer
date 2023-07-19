/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 08:36:54 by mfouadi           #+#    #+#             */
/*   Updated: 2023/07/19 08:49:57 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

#include "vectors.h"

typedef struct s_plane
{
	int					type;
	t_point				point;
	t_vec				nvec;
	t_color				color;
	struct s_plane		*next;
}	t_plane;

#endif // PLANE_H