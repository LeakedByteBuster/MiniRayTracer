/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 08:38:41 by absaid            #+#    #+#             */
/*   Updated: 2023/07/22 17:18:54 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minirt.h"

/* ************************************************************************** */
/*							Parsing Functions								  */
/* ************************************************************************** */
void	parsecam(t_data *data, char **s);
void	parsecy(t_data *data, char **s);
void	parselight(t_data *data, char **s);
void	parsesp(t_data *data, char **s);
void	parsepl(t_data *data, char **s);
void	rt_parsing(t_data *data, int fd);
void	ft_error(char *error, int status, int opt);
double	ft_atod(char *s);
int		ptrlen(char **ptr);
void	printdata(t_data *data);
void	check_ranges(t_data *data);

#endif // PARSER_H
