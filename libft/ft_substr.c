/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absaid <absaid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 07:27:06 by absaid            #+#    #+#             */
/*   Updated: 2023/07/22 15:52:08 by absaid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			i;
	unsigned int	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s + start);
	if (len > slen)
		len = slen;
	str = gc(len + 1, 1);
	if (!str)
		return (NULL);
	slen = ft_strlen(s);
	i = -1;
	while (++i < len && start[s] && start < slen)
		*(str + i) = *(s + start + i);
	str[i] = '\0';
	return (str);
}
