/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_sphere_intersection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:40:45 by mfouadi           #+#    #+#             */
/*   Updated: 2023/07/22 19:22:53 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"
#include "render.h"
#include "intersection_utils.h"
#include <stdbool.h>

static void	calcul_sol(t_eq2d *sol, t_utils *utils, t_sphere *sp)
{
	sol->a = dot_prod(utils->ray.direction, utils->ray.direction);
	sol->b = dot_prod(vecsub(utils->ray.origin, sp->center), \
		utils->ray.direction) * 2;
	sol->c = dot_prod(vecsub(utils->ray.origin, sp->center), \
		vecsub(utils->ray.origin, sp->center)) \
		- (sp->diam / 2) * (sp->diam / 2);
	sol->delta = (sol->b * sol->b) - (4 * sol->a * sol->c);
	return ;
}

bool	intersp(t_utils *utils, t_sphere *sp)
{
	t_eq2d	sol;
	double	t;

	t = 0;
	calcul_sol(&sol, utils, sp);
	if (sol.delta > 0)
	{
		sol.t1 = (-sol.b + sqrt(sol.delta)) / 2 * sol.a;
		sol.t2 = (-sol.b - sqrt(sol.delta)) / 2 * sol.a;
		t = (sol.t2 > sol.t1) * sol.t1 + (sol.t1 > sol.t2) * sol.t2;
	}
	else if (sol.delta == 0)
		t = -sol.b / 2 * sol.a;
	if ((t < utils->t.t || utils->t.t == -1) && t > EPS)
	{
		utils->t.t = t;
		utils->t.color = sp->color;
		utils->t.center = sp->center;
		utils->t.inter = vecadd(utils->ray.origin, \
			vecxnum(utils->ray.direction, t));
		utils->t.norm = normvec(vecsub(utils->t.inter, sp->center));
		return (true);
	}
	return (false);
}
