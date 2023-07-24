/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 08:39:57 by absaid            #+#    #+#             */
/*   Updated: 2023/07/23 21:43:00 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parser.h"

void	objparse(t_data *data, char *line)
{
	char	**s;

	s = ft_split(line, " \t", 0);
	if (!s || !(*s) || **s == '#')
		return ;
	if (!ft_strncmp(s[0], "C", 1) && (ft_strlen(s[0]) == 1))
		return (parsecam(data, s), (void)0);
	else if (!ft_strncmp(s[0], "A", 1) || !ft_strncmp(s[0], "L", 1))
		return (parselight(data, s), (void)0);
	else if (!ft_strncmp(s[0], "sp", 2) && (ft_strlen(s[0]) == 2))
		return (parsesp(data, s), (void)0);
	else if (!ft_strncmp(s[0], "cy", 2) && (ft_strlen(s[0]) == 2))
		return (parsecy(data, s), (void)0);
	else if (!ft_strncmp(s[0], "pl", 2) && (ft_strlen(s[0]) == 2))
		return (parsepl(data, s), (void)0);
	else
		ft_error("ERROR: Invalid Input rt.parsing.c", 1, 0);
	return ;
}

void	rt_parsing(t_data *data, int fd)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		objparse(data, line);
		free(line);
	}
	if (!data->cam || !data->amlight)
		ft_error("Error: Empty Map rt_parsing.c", 1, 0);
	return ;
}
