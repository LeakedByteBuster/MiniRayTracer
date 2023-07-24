/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 06:08:12 by absaid            #+#    #+#             */
/*   Updated: 2023/07/22 16:03:24 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gc.h"

void	*gc(size_t size, int param)
{
	static t_gc	*head;
	void		*address;

	if (param == 1)
	{
		address = malloc(size);
		if (!address)
			return (ft_gcclear(&head), exit(1), NULL);
		gcadd_front(&head, ft_gcnew(address));
		return (address);
	}
	(!param) && (ft_gcclear(&head), exit(1), 0);
	return (NULL);
}
