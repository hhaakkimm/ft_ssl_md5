/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 21:30:49 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/03/24 17:10:18 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ssl.h"

void		ft_data_sha256(char *str, t_data *m)
{
	int			i;
	uint64_t	size;

	size = ft_strlen(str);
	m->sz = 64;
	while ((m->sz - 8) <= size)
		m->sz += 64;
	m->word = (unsigned char *)ft_strnew(m->sz);
	i = 0;
	while (str[i])
	{
		m->word[i] = str[i];
		i++;
	}
	m->word[i] = 0x80;
	i = 8;
	size = swap_uint64(size * 8);
	ft_memcpy(&m->word[m->sz - i], &size, i);
}

void		ft_data_new(t_data *m, t_hash h, int max)
{
	int		i;
	char	*temp;
	char	*hash;
	char	*message;

	message = ft_strnew(64);
	i = 0;
	while (i < max)
	{
		hash = ft_itoa_base(h.h[i], 16);
		temp = ft_strjoin(message, hash);
		free(message);
		message = temp;
		i++;
	}
	m->message = message;
}

void		ft_data_md5(char *str, t_data *m)
{
	int			i;
	uint64_t	size;

	size = ft_strlen(str);
	m->sz = 64;
	while ((m->sz - 8) <= size)
		m->sz += 64;
	m->word = (unsigned char *)ft_strnew(m->sz);
	i = 0;
	while (str[i])
	{
		m->word[i] = str[i];
		i++;
	}
	m->word[i] = 0x80;
	size = size * 8;
	ft_memcpy(&m->word[m->sz - 8], &size, 8);
}
