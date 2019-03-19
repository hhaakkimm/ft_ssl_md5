/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 12:20:05 by aabdrakh          #+#    #+#             */
/*   Updated: 2018/09/20 12:20:06 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*s;

	s = (t_list *)malloc(sizeof(t_list));
	if (!s)
		return (NULL);
	if (content == NULL || content_size == 0)
	{
		s->content = NULL;
		s->content_size = 0;
	}
	else
	{
		s->content = ft_memalloc(content_size);
		s->content = ft_memcpy(s->content, content, content_size);
		s->content_size = content_size;
	}
	return (s);
}
