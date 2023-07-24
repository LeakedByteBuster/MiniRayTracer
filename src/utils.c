/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 09:16:42 by mfouadi           #+#    #+#             */
/*   Updated: 2023/07/20 20:38:57 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// Check if given file has ".rt" and open it, else return error
int	checkfile(char *file)
{
	int	len;

	len = ft_strlen(file) - 3;
	if (ft_strncmp(file + len, ".rt", 3))
		return (-1);
	return (open(file, O_RDONLY));
}

// Initilize members in struct "s_data"
void	initdata(t_data *data)
{
	data->amlight = NULL;
	data->cam = NULL;
	data->cyl = NULL;
	data->pl = NULL;
	data->sph = NULL;
	data->lights = NULL;
}
