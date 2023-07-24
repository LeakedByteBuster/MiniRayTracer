/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calculations_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:48:16 by mfouadi           #+#    #+#             */
/*   Updated: 2023/07/22 16:49:46 by mfouadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"
#include <math.h>

double	lengthvec(t_vec v)
{
	return (sqrt(dot_prod(v, v)));
}

t_vec	normvec(t_vec v)
{
	return (vecxnum(v, 1 / lengthvec(v)));
}
