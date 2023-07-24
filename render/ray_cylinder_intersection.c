/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cylinder_intersection.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 11:48:38 by mfouadi           #+#    #+#             */
/*   Updated: 2023/07/22 19:43:46 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"
#include "render.h"
#include "intersection_utils.h"

/*
*	C is the start cap point of the cylinder
*	V is a unit length vector that determines cylinder's axis
*	r is the cylinder's radius
*	maxm determines cylinder's end cap point 
	a   = D|D - (D|V)^2
	b/2 = D|X - (D|V)*(X|V)
	c   = X|X - (X|V)^2 - r*r
	x	= O - C : O:Ray Origin C: Center of the shape
	m	= D|V*t + X|V

	P - C = D*t + X
	------------------
	Surface normal is:
	------------------
	m = D|V*t + X|V
	N = nrm( P-C-V*m )
*/

static double
	get_both_solutions_for_t(t_eq2d *sol, t_cylinder *cyl, \
		t_vec x, t_utils *utils)
{
	double	m[2];
	double	t;

	t = 0.0;
	sol->t1 = (-sol->b - sqrt(sol->delta)) / (2 * sol->a);
	sol->t2 = (-sol->b + sqrt(sol->delta)) / (2 * sol->a);
	m[0] = (dot_prod(utils->ray.direction, vecxnum(cyl->nvec, sol->t1))) \
		+ dot_prod(x, cyl->nvec);
	m[1] = (dot_prod(utils->ray.direction, vecxnum(cyl->nvec, sol->t2))) \
		+ dot_prod(x, cyl->nvec);
	if (sol->t2 < EPS)
		return (false);
	if (((m[0] >= EPS) && (m[0] < cyl->height)))
		t = sol->t1;
	else if (((m[1] >= EPS) && (m[1] < cyl->height)))
		t = sol->t2;
	return (t);
}

static bool	fill_t(t_utils *utils, t_cylinder *cyl, t_vec x, double t)
{
	double	m;

	utils->t.t = t;
	utils->t.color = cyl->color;
	utils->t.center = cyl->center;
	m = dot_prod(utils->ray.direction, \
		vecxnum(cyl->nvec, t)) + dot_prod(x, cyl->nvec);
	utils->t.inter = vecadd(utils->ray.origin, \
		vecxnum(utils->ray.direction, t));
	utils->t.norm = normvec(vecsub(vecadd(\
		vecxnum(utils->ray.direction, t), x), vecxnum(cyl->nvec, m)));
	return (true);
}

bool	ray_cylinder_intersection(t_utils *utils, t_cylinder *cyl)
{
	t_eq2d	sol;
	double	t;
	t_vec	x;

	t = 0.0;
	x = vecsub(utils->ray.origin, cyl->center);
	sol.a = dot_prod(utils->ray.direction, utils->ray.direction) - \
		pow(dot_prod(utils->ray.direction, cyl->nvec), 2);
	sol.b = 2 * (dot_prod(utils->ray.direction, x) \
		- (dot_prod(utils->ray.direction, cyl->nvec) * dot_prod(x, cyl->nvec)));
	sol.c = dot_prod(x, x) - pow(dot_prod(x, cyl->nvec), 2) \
		- pow(cyl->diam / 2, 2);
	sol.delta = (sol.b * sol.b) - (4 * sol.a * sol.c);
	if (sol.delta >= EPS)
		t = get_both_solutions_for_t(&sol, cyl, x, utils);
	if ((t < utils->t.t || utils->t.t == -1) && t > EPS)
	{
		return (fill_t(utils, cyl, x, t));
	}
	return (false);
}
