/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 15:18:03 by aabdrakh          #+#    #+#             */
/*   Updated: 2018/09/16 18:55:21 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*f;
	unsigned char	cc;

	f = (unsigned char *)s;
	i = 0;
	cc = (unsigned char)c;
	while (i < n)
	{
		if (*f == cc)
			return (f);
		f++;
		i++;
	}
	return (NULL);
}
