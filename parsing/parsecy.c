/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsecy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 18:21:20 by absaid            #+#    #+#             */
/*   Updated: 2023/07/22 18:38:07 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parser.h"

static void	add_cylinder_back(t_cylinder **head, t_cylinder *new)
{
	t_cylinder	*tmp;

	if (!*head)
		return (*head = new, (void)0);
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

static void	input_checker(char **s)
{
	(ptrlen(s) != 6) && (ft_error("Error : parsecy.c\n", 1, 0), 0);
	(ft_strchr(",", s[1][0]) || ft_strchr(",", s[1][ft_strlen(s[1]) - 1])) \
		&& (ft_error("Error\n", 1, 0), 0);
	(ft_strchr(",", s[2][0]) || ft_strchr(",", s[2][ft_strlen(s[2]) - 1])) \
		&& (ft_error("Error\n", 1, 0), 0);
	(ft_strchr(",", s[5][0]) || ft_strchr(",", s[5][ft_strlen(s[5]) - 1])) \
		&& (ft_error("Error\n", 1, 0), 0);
	return ;
}

void	parsecy(t_data *data, char **s)
{
	char		**coordp;
	char		**vec;
	char		**rgb;
	t_cylinder	*cy;

	cy = gc(sizeof(t_cylinder), 1);
	input_checker(s);
	coordp = ft_split(s[1], ",", 1);
	(ptrlen(coordp) != 3) && (ft_error("Error : parsecy.c\n", 1, 0), 0);
	vec = ft_split(s[2], ",", 1);
	(ptrlen(vec) != 3) && (ft_error("Error : parsecy.c\n", 1, 0), 0);
	rgb = ft_split(s[5], ",", 1);
	(ptrlen(rgb) != 3) && (ft_error("Error : parsecy.c\n", 1, 0), 0);
	cy->type = CYLINDER;
	cy->center = (t_point){
		ft_atod(coordp[0]), ft_atod(coordp[1]), ft_atod(coordp[2])};
	cy->nvec = (t_vec){ft_atod(vec[0]), ft_atod(vec[1]), ft_atod(vec[2])};
	cy->diam = ft_atod(s[3]);
	cy->height = ft_atod(s[4]);
	cy->color = (t_color){ft_atoi(rgb[0], 1), ft_atoi(rgb[1], 1), \
		ft_atoi(rgb[2], 1)};
	cy->next = NULL;
	add_cylinder_back(&(data->cyl), cy);
}
