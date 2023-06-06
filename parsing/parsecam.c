/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsecam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:57:10 by absaid            #+#    #+#             */
/*   Updated: 2023/06/06 11:33:13 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt_parser.h"

void parsecam(t_data *data, char **s)
{
	char **const coordp = ft_split(s[1], ",", 1);
	char **const coordv = ft_split(s[2], ",", 1);

	// TODO: Coding our own atoi and ft_atod if we consider that sunch input
	(ft_strchr(",", s[1][0]) || ft_strchr(",", s[1][ft_strlen(s[1]) - 1])) && (puts("erroor m9aaawed"), exit(1), 0);
	(ft_strchr(",", s[2][0]) || ft_strchr(",", s[2][ft_strlen(s[2]) - 1])) && (puts("erroor m9aaawed"), exit(1), 0);
	if (data->cam)
		return (puts("cam is already exist"), exit(1), (void)0); // ft_error
	data->cam = gc(sizeof(t_cam), 1);
	data->cam->type = CAMERA;
	data->cam->center = (t_point){
		ft_atod(coordp[0]),
		ft_atod(coordp[1]),
		ft_atod(coordp[2])};
	data->cam->nvec = (t_vec){
		ft_atod(coordv[0]),
		ft_atod(coordv[1]),
		ft_atod(coordv[2])};
	data->cam->FOV = ft_atoi(s[3], 0);
  	(coordp[3]) && (ft_error("Error\n", 1, 0), 0);
	  (coordv[3]) && (ft_error("Error\n", 1, 0), 0);
	if (s[4])
		return (puts("num of args invalid"), exit(0), (void)0);
}
