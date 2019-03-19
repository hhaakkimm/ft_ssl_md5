/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 01:54:48 by aabdrakh          #+#    #+#             */
/*   Updated: 2018/09/16 14:24:42 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n;
	char	*s1;
	char	*s2;

	i = 0;
	n = ft_strlen(needle);
	if (*needle == '\0')
		return ((char *)haystack);
	while (i < len && *haystack)
	{
		s1 = (char *)haystack;
		s2 = (char *)needle;
		while (*s1 == *s2 && *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0' && ((i + n) <= len))
			return ((char *)haystack);
		i++;
		haystack++;
	}
	return (NULL);
}
