/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 08:35:26 by mfouadi           #+#    #+#             */
/*   Updated: 2023/07/22 17:09:55 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# include "vectors.h"

/* ************************************************************************** */
/*								Colors										  */
/* ************************************************************************** */
t_color	coefcolor(t_color c1, t_color c2, double coef);
t_color	coloradd(t_color c1, t_color c2);
t_color	colormix(t_color c1, t_color c2);

#endif // COLORS_H