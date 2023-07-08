/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 07:56:30 by absaid            #+#    #+#             */
/*   Updated: 2023/07/06 21:38:31 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
#include "../includes/rt_parser.h"

/*
	• Allowed functions :
		open, close, read, write,
		printf, malloc, free, perror,
		strerror, exit
	• All functions of the math library (-lm man man 3 math)
	• All functions of the MinilibX
*/

int checkfile(char *file)
{
	int len;

	len = ft_strlen(file) - 3;
	if (ft_strncmp(file + len, ".rt", 3))
		return (-1);
	return (open(file, O_RDONLY));
}

// Initilizes mlx params;
void initdata(t_data *data)
{
	data->amlight = NULL;
	data->cam = NULL;
	data->cyl = NULL;
	data->pl = NULL;
	data->sph = NULL;
	data->lights = NULL;
}

/* ************************************************************************** */
/*							TODO LIST										  */
/* ************************************************************************** */
/*
	// TODO : There are some maps that have an xpm file for texture
	// TODO :  'tx'...
	// TODO : Handle problem of parsing 255,,,,,255,255
	// TODO: Freeing the 3 double pointers?? parsecy(), parsepl()...
	// TODO: Freeing the pointer in the inner while?? rt_parsing

*/

int main(int ac, char **av)
{
	int fd;
	t_data data;

	if (ac != 2)
		ft_error("Invalid Arguments", 1, 0);
	fd = checkfile(av[1]);
	if (fd < 0)
		ft_error("Invalid File", 1, 0);
	initdata(&data);
	rt_parsing(&data, fd);
	check_ranges(&data);
	// printdata(&data);
	rt_rendering(&data);
}
