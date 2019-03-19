/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 18:29:36 by aabdrakh          #+#    #+#             */
/*   Updated: 2018/09/13 18:35:25 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <string.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*c;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	c = ft_strnew(ft_strlen(s));
	i = 0;
	if (!c)
		return (NULL);
	while (s[i] != '\0')
	{
		c[i] = (*f)(i, s[i]);
		i++;
	}
	return (c);
}
