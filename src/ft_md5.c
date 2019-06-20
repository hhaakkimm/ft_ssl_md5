/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 21:49:27 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/06/19 22:15:26 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ssl.h"

void		ft_md5(char *str, t_data *m)
{
	size_t		size;
	t_hash		hash;

	hash.h[0] = 0x67452301;
	hash.h[1] = 0xefcdab89;
	hash.h[2] = 0x98badcfe;
	hash.h[3] = 0x10325476;
	ft_data_md5(str, m);
	size = 0;
	while (size < m->sz)
	{
		ft_blocks_md5(&m->word[size], &hash);
		size += 64;
	}
	free(m->word);
	hash.h[0] = swap_uint32(hash.h[0]);
	hash.h[1] = swap_uint32(hash.h[1]);
	hash.h[2] = swap_uint32(hash.h[2]);
	hash.h[3] = swap_uint32(hash.h[3]);
	ft_data_new(m, hash, 4);
}

void		ft_blocks_md5(unsigned char *padded, t_hash *hash)
{
	int			i;
	int			size;
	uint32_t	m[16];

	i = 0;
	size = 0;
	while (i < 16)
	{
		ft_memcpy(&m[i], (padded + size), 4);
		size += 4;
		i++;
	}
	ft_mainloop_md5(hash, m);
}

void		ft_mainloop_md5(t_hash *hash, uint32_t *m)
{
	int				i;
	t_reg			r;
	uint32_t		*k;
	static uint32_t	s[64] = {
		7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
		5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
		4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
		6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21
	};

	k = ft_reg_md5();
	i = -1;
	while (++i < 4)
		r.el[i] = hash->h[i];
	r.el[8] = 0;
	while (r.el[8] < 64)
	{
		ft_rotation_md5(&r, m, k, s);
		r.el[8]++;
	}
	i = -1;
	while (++i < 4)
		hash->h[i] += r.el[i];
}

uint32_t	*ft_reg_md5(void)
{
	static uint32_t	k[64] = {
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee, 0xf57c0faf, 0x4787c62a,
	0xa8304613, 0xfd469501, 0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821, 0xf61e2562, 0xc040b340,
	0x265e5a51, 0xe9b6c7aa, 0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed, 0xa9e3e905, 0xfcefa3f8,
	0x676f02d9, 0x8d2a4c8a, 0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70, 0x289b7ec6, 0xeaa127fa,
	0xd4ef3085, 0x04881d05, 0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039, 0x655b59c3, 0x8f0ccc92,
	0xffeff47d, 0x85845dd1, 0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
	};

	return (k);
}

void		ft_rotation_md5(t_reg *r, uint32_t *m, uint32_t *k, uint32_t *s)
{
	if (r->el[8] < 16)
	{
		r->el[5] = F(r->el[1], r->el[2], r->el[3]);
		r->el[6] = r->el[8];
	}
	else if (r->el[8] < 32)
	{
		r->el[5] = G(r->el[1], r->el[2], r->el[3]);
		r->el[6] = ((5 * r->el[8]) + 1) % 16;
	}
	else if (r->el[8] < 48)
	{
		r->el[5] = H(r->el[1], r->el[2], r->el[3]);
		r->el[6] = ((3 * r->el[8]) + 5) % 16;
	}
	else if (r->el[8] < 64)
	{
		r->el[5] = I(r->el[1], r->el[2], r->el[3]);
		r->el[6] = (7 * r->el[8]) % 16;
	}
	r->el[4] = r->el[3];
	r->el[3] = r->el[2];
	r->el[2] = r->el[1];
	r->el[1] += ROTL((r->el[5] + r->el[0] + k[r->el[8]] + m[r->el[6]]), s[r->el[8]]);
	r->el[0] = r->el[4];
}
