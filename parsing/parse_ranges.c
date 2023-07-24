/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ranges.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 02:26:55 by mfouadi           #+#    #+#             */
/*   Updated: 2023/07/20 20:42:36 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parser.h"

#ifndef ERROR_NVEC
# define ERROR_NVEC "Error: invalid range for normalized 3d vector \
in range [-1, 1] parse_ranges.c"
#endif // ERROR_NVEC

#ifndef ERROR_AMB
# define ERROR_AMB "Error: ambiant light in range [0.0,1.0] parse_ranges.c"
#endif // ERROR_NVEC

#ifndef ERROR_LIGHT
# define ERROR_LIGHT "Error: the light brightness ratio in range [0.0,1.0] \
	parse_ranges.c"
#endif // ERROR_LIGHT

static void	parse_nvec_ranges(t_vec *nvec)
{
	if (!nvec)
		ft_error(ERROR_NVEC, 1, 0);
	if ((nvec->x < -1.0 || nvec->x > 1.0) || (nvec->y < -1.0 || nvec->y > 1.0)
		|| (nvec->z < -1.0 || nvec->z > 1.0))
		ft_error(ERROR_NVEC, 1, 0);
	return ;
}

static void	parse_light_ranges(double light, double amb_light, bool check)
{
	if (check == 0)
	{
		if (light > 1.0 || light < 0)
			ft_error(ERROR_LIGHT, 1, 0);
	}
	else
	{
		if (amb_light < 0 || amb_light > 1)
			ft_error(ERROR_AMB, 1, 0);
	}
	return ;
}

void	check_ranges(t_data *data)
{
	t_cylinder	*cy_nvec;
	t_plane		*pl_nvec;

	pl_nvec = data->pl;
	while (pl_nvec)
	{
		if (pl_nvec)
			parse_nvec_ranges(&pl_nvec->nvec);
		pl_nvec = pl_nvec->next;
	}
	cy_nvec = data->cyl;
	while (cy_nvec)
	{
		if (cy_nvec)
			parse_nvec_ranges(&cy_nvec->nvec);
		cy_nvec = cy_nvec->next;
	}
	if (data->cam)
		parse_nvec_ranges(&data->cam->forvec);
	if (data->lights)
		parse_light_ranges(data->lights->range, 0, 0);
	if (data->amlight)
		parse_light_ranges(0, data->amlight->range, 1);
	return ;
}
