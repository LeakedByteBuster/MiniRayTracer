/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:17:25 by mfouadi           #+#    #+#             */
/*   Updated: 2023/07/22 17:11:14 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

typedef struct s_mlx_image
{
	char	*addr;
	void	*img;
	int		bits_per_pixel;
	int		endian;
	int		line_length;
}	t_img;

#endif // IMAGE_H