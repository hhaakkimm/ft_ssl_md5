/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha256.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 16:04:29 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/03/24 22:45:06 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_ssl.h"

void		ft_sha256(char *str, t_data *m)
{
	size_t		size;
	t_hash		hash;

	hash.h[0] = 0x6a09e667;
	hash.h[1] = 0xbb67ae85;
	hash.h[2] = 0x3c6ef372;
	hash.h[3] = 0xa54ff53a;
	hash.h[4] = 0x510e527f;
	hash.h[5] = 0x9b05688c;
	hash.h[6] = 0x1f83d9ab;
	hash.h[7] = 0x5be0cd19;
	ft_data_sha256(str, m);
	size = 0;
	while (size < m->sz)
	{
		ft_blocks_sha256(&m->word[size], &hash);
		size += 64;
	}
	free(m->word);
	ft_data_new(m, hash, 8);
}

void		ft_blocks_sha256(unsigned char *padded, t_hash *hash)
{
	int			i;
	int			size;
	uint32_t	m[16];

	i = 0;
	size = 0;
	while (i < 16)
	{
		ft_memcpy(&m[i], (padded + size), 4);
		m[i] = swap_uint32(m[i]);
		size += 4;
		i++;
	}
	ft_mainloop_sha256(hash, m);
}

void		ft_mainloop_sha256(t_hash *hash, uint32_t *m)
{
	int			i;
	uint32_t	w[64];
	t_reg		r;
	uint32_t	*k;

	k = ft_reg_sha256();
	i = -1;
	while (++i < 8)
		r.el[i] = hash->h[i];
	i = 0;
	while (i < 64)
	{
		if (i < 16)
			w[i] = m[i];
		else
			w[i] = S1(w[i - 2]) + w[i - 7] + S0(w[i - 15]) + w[i - 16];
		i++;
	}
	ft_rotation_sha256(r, hash, k, w);
}

void		ft_rotation_sha256(t_reg r, t_hash *hash, uint32_t *k, uint32_t *w)
{
	int	i;
	int	j;

	i = 0;
	while (i < 64)
	{
		j = 8;
		r.el[8] = r.el[7] + E1(r.el[4]) + CH(r.el[4], r.el[5], r.el[6]) + k[i] + w[i];
		r.el[9] = E0(r.el[0]) + MAJ(r.el[0], r.el[1], r.el[2]);
		while (--j > 0)
			r.el[j] = r.el[j - 1];
		r.el[4] += r.el[8];
		r.el[0] = r.el[8] + r.el[9];
		i++;
	}
	j = -1;
	while (++j < 8)
		hash->h[j] += r.el[j];
}

uint32_t	*ft_reg_sha256(void)
{
	static uint32_t k[64] = {
		0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1,
		0x923f82a4, 0xab1c5ed5, 0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
		0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174, 0xe49b69c1, 0xefbe4786,
		0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
		0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147,
		0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
		0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, 0xa2bfe8a1, 0xa81a664b,
		0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
		0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a,
		0x5b9cca4f, 0x682e6ff3, 0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
		0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
	};

	return (k);
}
