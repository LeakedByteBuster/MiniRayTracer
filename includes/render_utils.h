/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:04:08 by mfouadi           #+#    #+#             */
/*   Updated: 2023/07/22 17:20:11 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_UTILS_H
# define RENDER_UTILS_H

# include "vectors.h"
# include "image.h"

typedef struct s_solution
{
	double	t;
	t_point	center;
	t_point	inter;
	t_vec	lvec;
	t_vec	norm;
	t_vec	r_norm;
	t_color	color;
}	t_solution;

void	put_pixel_on_image(t_img *img, int x, int y, int color);

#endif // RENDER_UTILS_H
