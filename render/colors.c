/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 06:23:06 by mfouadi           #+#    #+#             */
/*   Updated: 2023/07/20 21:35:36 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

t_color	coefcolor(t_color c1, t_color c2, double coef)
{
	t_color	c;

	c.x = c1.x * (c2.x / 255) * coef;
	c.y = c1.y * (c2.y / 255) * coef;
	c.z = c1.z * (c2.z / 255) * coef;
	return (c);
}

t_color	coloradd(t_color c1, t_color c2)
{
	t_color	c;

	c = vecadd(c1, c2);
	(c.x > 255) && (c.x = 255);
	(c.y > 255) && (c.y = 255);
	(c.z > 255) && (c.z = 255);
	return (c);
}

t_color	colormix(t_color c1, t_color c2)
{
	t_color	c;

	c.x = c1.x * (c2.x / 255);
	c.y = c1.y * (c2.y / 255);
	c.z = c1.z * (c2.z / 255);
	return (c);
}
