/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 08:44:55 by mfouadi           #+#    #+#             */
/*   Updated: 2023/07/22 17:06:09 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

typedef struct s_3d
{
	double		x;
	double		y;
	double		z;
} t_vec, t_point,	t_color;

typedef struct s_ray
{
	t_point	origin;
	t_vec	direction;
	int		red;
	int		green;
}	t_ray;

/* ************************************************************************** */
/*							Vector Calculations								  */
/* ************************************************************************** */
double	dot_prod(t_vec v, t_vec u);
t_vec	cross_prod(t_vec v, t_vec u);
t_vec	vecadd(t_vec v, t_vec u);
t_vec	vecxnum(t_vec v, double nb);
t_vec	vecsub(t_vec v, t_vec u);
t_vec	normvec(t_vec v);
double	lengthvec(t_vec v);

#endif // VECTORS_H