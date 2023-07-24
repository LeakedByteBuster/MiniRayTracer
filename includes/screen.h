/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 08:37:12 by mfouadi           #+#    #+#             */
/*   Updated: 2023/07/22 18:22:38 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_H
# define SCREEN_H

# include "image.h"

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_img		*img;
	double		n_width;
	double		n_height;
	double		pixel;
}	t_mlx;

#endif // SCREEN_H