/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 08:39:47 by mfouadi           #+#    #+#             */
/*   Updated: 2023/07/22 19:49:18 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "colors.h"
// #include "plane.h"

typedef struct s_tmp{
	t_sphere	*sphere;
	t_cylinder	*cylinder;
	t_plane		*plane;
}	t_tmp;

static void
	shadow_or_object_color(t_tmp *tmp, t_utils *utils, t_color c, \
		bool *is_shadow)
{
	while (tmp->sphere)
	{
		if (intersp(utils, tmp->sphere))
		{
			*is_shadow = true;
			utils->t.color = colormix(c, vecxnum(utils->am->color, \
				utils->am->range));
			return ;
		}
		tmp->sphere = tmp->sphere->next;
	}
	while (tmp->cylinder)
	{
		if (ray_cylinder_intersection(utils, tmp->cylinder))
		{
			*is_shadow = true;
			utils->t.color = colormix(c, vecxnum(utils->am->color, \
				utils->am->range));
			return ;
		}
		tmp->cylinder = tmp->cylinder->next;
	}
}

static void	specular_light(t_utils *utils, t_solution *T)
{
	t_color	speclight;
	double	specular;
	double	dot2;

	dot2 = dot_prod(normvec(T->r_norm), \
		normvec(vecsub(utils->ray.origin, T->inter)));
	if (dot2 <= 0)
	{
		speclight = (t_color){0, 0, 0};
	}
	else
	{
		specular = 0.4 * pow(dot2, 60);
		speclight = vecxnum(utils->l->color, specular);
	}
	T->color = coloradd(T->color, speclight);
	return ;
}

static void	calcul_light_value(t_utils *utils)
{
	t_solution	*solution_data;
	t_color		diffuse;
	t_color		ambiant;
	t_color		lights;
	double		dot;

	solution_data = &(utils->t);
	solution_data->lvec = normvec(vecsub(utils->l->pos, solution_data->inter));
	dot = dot_prod(solution_data->norm, solution_data->lvec);
	if (dot > 0)
	{
		solution_data->r_norm = normvec(\
			vecsub(vecxnum(solution_data->norm, 2 * dot), solution_data->lvec));
		diffuse = vecxnum(utils->l->color, dot * utils->l->range);
		ambiant = vecxnum(utils->am->color, utils->am->range);
		lights = coloradd(diffuse, ambiant);
		solution_data->color = colormix(solution_data->color, lights);
		specular_light(utils, solution_data);
	}
	else
	{
		ambiant = vecxnum(utils->am->color, utils->am->range);
		solution_data->color = colormix(solution_data->color, ambiant);
	}
	return ;
}

void	check_light_for_current_pixel(t_data *data, t_utils *utils)
{
	bool	is_shadow;
	t_ray	tmp_ray;
	t_color	c;
	t_tmp	tmp;

	c = utils->t.color;
	tmp_ray = utils->ray;
	is_shadow = false;
	utils->ray.origin = utils->t.inter;
	utils->ray.direction = normvec(vecsub(utils->l->pos, utils->t.inter));
	tmp.sphere = data->sph;
	tmp.cylinder = data->cyl;
	tmp.plane = data->pl;
	shadow_or_object_color(&tmp, utils, c, &is_shadow);
	utils->ray = tmp_ray;
	if (!is_shadow)
		calcul_light_value(utils);
	return ;
}
