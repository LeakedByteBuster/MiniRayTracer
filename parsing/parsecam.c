/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsecam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:57:10 by absaid            #+#    #+#             */
/*   Updated: 2023/07/22 17:16:50 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "minirt.h"
#include "parser.h"

void	parsecam(t_data *data, char **s)
{
	char	**coordp;
	char	**coordv;

	(ptrlen(s) != 4) && (ft_error("Error : parsecam.c\n", 1, 0), 0);
	(ft_strchr(",", s[1][0]) || ft_strchr(",", s[1][ft_strlen(s[1]) - 1])) \
		&& (ft_error("Error\n", 1, 0), 0);
	(ft_strchr(",", s[2][0]) || ft_strchr(",", s[2][ft_strlen(s[2]) - 1])) \
		&& (ft_error("Error\n", 1, 0), 0);
	coordp = ft_split(s[1], ",", 1);
	(ptrlen(coordp) != 3) && (ft_error("Error : parsecam.c\n", 1, 0), 0);
	coordv = ft_split(s[2], ",", 1);
	(ptrlen(coordv) != 3) && (ft_error("Error : parsecam.c\n", 1, 0), 0);
	if (data->cam)
		return (ft_error("Error : double cam parsecam.c\n", 1, 0), (void)0);
	data->cam = gc(sizeof(t_cam), 1);
	data->cam->type = CAMERA;
	data->cam->center = (t_point){
		ft_atod(coordp[0]),
		ft_atod(coordp[1]),
		ft_atod(coordp[2])};
	data->cam->forvec = (t_vec){
		ft_atod(coordv[0]),
		ft_atod(coordv[1]),
		ft_atod(coordv[2])};
	data->cam->fov = ft_atoi(s[3], 0);
}
