/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 07:25:05 by absaid            #+#    #+#             */
/*   Updated: 2023/07/22 18:38:19 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include <limits.h>

#ifndef ERROR_MSG_ATOI
# define ERROR_MSG_ATOI "ERROR: incorrect Input ft_atoi.c\n"
#endif // ERROR_MSG_ATOI

#ifndef ERROR_MSG_RANGE
# define ERROR_MSG_RANGE "ERROR: out of range [ color in range [0, 255] | \
Camera FOV in range [0, 180] ] ft_atoi.c\n"
#endif // ERROR_MSG_RANGE

static void	ft_error(char *error, int status, int opt)
{
	if (opt == 1)
		perror(error);
	if (opt == 0)
		write(2, error, ft_strlen(error));
	exit(status);
}

static void
	init_vars(int *i, int *n, int *result, unsigned long long int *check)
{
	*i = 0;
	*n = 1;
	*result = 0;
	*check = 0;
	return ;
}

int	ft_atoi(const char *str, int mode)
{
	int						i;
	int						n;
	unsigned long long int	check;
	int						result;

	if (!str)
		ft_error(ERROR_MSG_ATOI, 1, 0);
	init_vars(&i, &n, &result, &check);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			ft_error(ERROR_MSG_RANGE, 1, 0);
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		check = result * 10 + str[i] - '0';
		if (check > INT_MAX)
			ft_error("Error: Overflow in input: INT_MAX", 1, 0);
		result = check;
		i++;
	}
	if (str[i] != '\0' || (mode && result > 255) || (!mode && result > 180))
		ft_error(ERROR_MSG_RANGE, 1, 0);
	return ((int)result * n);
}
