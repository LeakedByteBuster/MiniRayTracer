/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseplane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 23:14:11 by absaid            #+#    #+#             */
/*   Updated: 2023/07/22 19:02:12 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parser.h"

static void	add_plane_back(t_plane **head, t_plane *new)
{
	t_plane	*tmp;

	if (!*head)
		return (*head = new, (void)0);
	tmp = *head;
	while (tmp -> next)
		tmp = tmp -> next;
	tmp -> next = new;
}

static void	input_checker(char **s)
{
	(ptrlen(s) != 4) && (ft_error("Error : parseplane.c1\n", 1, 0), 0);
	(ft_strchr(",", s[1][0]) || ft_strchr(",", s[1][ft_strlen(s[1]) - 1])) \
		&& (ft_error("Error\n", 1, 0), 0);
	(ft_strchr(",", s[2][0]) || ft_strchr(",", s[2][ft_strlen(s[2]) - 1])) \
		&& (ft_error("Error\n", 1, 0), 0);
	(ft_strchr(",", s[3][0]) || ft_strchr(",", s[3][ft_strlen(s[3]) - 1])) \
		&& (ft_error("Error\n", 1, 0), 0);
	return ;
}

void	parsepl(t_data *data, char **s)
{
	t_plane	*pl;
	char	**coordp;
	char	**coordv;
	char	**rgb;

	input_checker(s);
	pl = gc(sizeof(t_cylinder), 1);
	rgb = ft_split(s[3], ",", 1);
	(ptrlen(rgb) != 3) && (ft_error("Error : parseplane.c\n", 1, 0), 0);
	coordv = ft_split(s[2], ",", 1);
	(ptrlen(coordv) != 3) && (ft_error("Error : parseplane.c\n", 1, 0), 0);
	coordp = ft_split(s[1], ",", 1);
	(ptrlen(coordp) != 3) && (ft_error("Error : parseplane.c\n", 1, 0), 0);
	pl->type = PLANE;
	pl->point = (t_point){ft_atod(coordp[0]), \
		ft_atod(coordp[1]), ft_atod(coordp[2])};
	pl->nvec = (t_vec){ft_atod(coordv[0]), \
		ft_atod(coordv[1]), ft_atod(coordv[2])};
	pl->color = (t_color){ft_atoi(rgb[0], 1), ft_atoi(rgb[1], 1), \
		ft_atoi(rgb[2], 1)};
	pl->next = NULL;
	add_plane_back(&(data->pl), pl);
}
