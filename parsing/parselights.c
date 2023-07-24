/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parselights.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 18:40:59 by absaid            #+#    #+#             */
/*   Updated: 2023/07/22 18:58:44 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parser.h"

static void	add_light_back(t_light **head, t_light *new)
{
	t_light	*tmp;

	if (!*head)
		return (*head = new, (void)0);
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return ;
}

static void	init_light(char	**rgb, char	**coord, t_light **light, char **s)
{
	(ptrlen(s) != 4) && (ft_error("Error : Double A", 1, 0), 0);
	(ft_strchr(",", s[1][0]) || ft_strchr(",", s[1][ft_strlen(s[1]) - 1])) \
		&& (ft_error("Error: parse_light.c\n", 1, 0), 0);
	(ft_strchr(",", s[3][0]) || ft_strchr(",", s[3][ft_strlen(s[3]) - 1])) \
		&& (ft_error("Error: parse_light.c\n", 1, 0), 0);
	*light = gc(sizeof(t_light), 1);
	(*light)->type = LIGHT;
	coord = ft_split(s[1], ",", 1);
	(ptrlen(coord) != 3) && (ft_error("Error : parselight.c\n", 1, 0), 0);
	rgb = ft_split(s[3], ",", 1);
	(ptrlen(rgb) != 3) && (ft_error("Error : parselight.c\n", 1, 0), 0);
	(*light)->pos = (t_point){
		ft_atod(coord[0]),
		ft_atod(coord[1]),
		ft_atod(coord[2])
	};
	(*light)->color = (t_color){ft_atoi(rgb[0], 1), \
		ft_atoi(rgb[1], 1), ft_atoi(rgb[2], 1)};
	(*light)->range = ft_atod(s[2]);
	(*light)->next = NULL;
	return ;
}

void	parselight(t_data *data, char **s)
{
	char	**rgb;
	char	**coord;
	t_light	*light;

	rgb = NULL;
	coord = NULL;
	light = NULL;
	if (!ft_strncmp(s[0], "A", 1))
	{
		(data->amlight || ptrlen(s) != 3) \
			&& (ft_error("Error : Double A", 1, 0), 0);
		data->amlight = gc(sizeof(t_light), 1);
		data->amlight->type = AMBIENT_LIGHT;
		(ft_strchr(",", s[2][0]) || ft_strchr(",", s[2][ft_strlen(s[2]) - 1])) \
			&& (ft_error("Error: parse_light.c\n", 1, 0), 0);
		rgb = ft_split(s[2], ",", 1);
		(ptrlen(rgb) != 3) && (ft_error("Error : parselight.c\n", 1, 0), 0);
		data->amlight->color = (t_color){ft_atoi(rgb[0], 1), \
			ft_atoi(rgb[1], 1), ft_atoi(rgb[2], 1)};
		return (data->amlight->range = ft_atod(s[1]), (void)0);
	}
	else
		init_light(rgb, coord, &light, s);
	return (add_light_back(&(data->lights), light));
}
