/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsesp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:34:22 by absaid            #+#    #+#             */
/*   Updated: 2023/07/20 21:22:55 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parser.h"

static void	add_sphere_back(t_sphere **head, t_sphere *new)
{
	t_sphere	*tmp;

	if (!*head)
		return (*head = new, (void)0);
	tmp = *head;
	while (tmp -> next)
		tmp = tmp -> next;
	tmp -> next = new;
}

void	parsesp(t_data *data, char **s)
{
	t_sphere	*sp;
	char		**coordp;
	char		**rgb;

	sp = gc(sizeof(t_sphere), 1);
	(ptrlen(s) != 4) && (ft_error("Error : parsesp.c\n", 1, 0), 0);
	(ft_strchr(",", s[3][0]) || ft_strchr(",", s[3][ft_strlen(s[3]) - 1])) \
		&& (ft_error("Error : parsesp.c\n", 1, 0), 0);
	(ft_strchr(",", s[1][0]) || ft_strchr(",", s[1][ft_strlen(s[1]) - 1])) \
		&& (ft_error("Error : parsesp.c\n", 1, 0), 0);
	coordp = ft_split(s[1], ",", 1);
	(ptrlen(coordp) != 3) && (ft_error("Error : parsesp.c\n", 1, 0), 0);
	rgb = ft_split(s[3], ",", 1);
	(ptrlen(rgb) != 3) && (ft_error("Error : parsesp.c\n", 1, 0), 0);
	sp->type = SPHERE;
	sp->center = (t_point){
		ft_atod(coordp[0]),
		ft_atod(coordp[1]),
		ft_atod(coordp[2])
	};
	sp->diam = ft_atod(s[2]);
	sp->color = (t_color){ft_atoi(rgb[0], 1), ft_atoi(rgb[1], 1), \
		ft_atoi(rgb[2], 1)};
	sp->next = NULL;
	add_sphere_back(&(data->sph), sp);
}
