/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sha512.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 21:53:19 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/06/19 22:15:26 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ssl.h"

static void					init_data(t_sha_data512 *tmp)
{
	tmp->h0 = 0x6a09e667f3bcc908;
	tmp->h1 = 0xbb67ae8584caa73b;
	tmp->h2 = 0x3c6ef372fe94f82b;
	tmp->h3 = 0xa54ff53a5f1d36f1;
	tmp->h4 = 0x510e527fade682d1;
	tmp->h5 = 0x9b05688c2b3e6c1f;
	tmp->h6 = 0x1f83d9abfb41bd6b;
	tmp->h7 = 0x5be0cd19137e2179;
}

static void					add_data(t_sha_data512 *tmp)
{
	tmp->h = tmp->g;
	tmp->g = tmp->f;
	tmp->f = tmp->e;
	tmp->e = tmp->d + tmp->t1;
	tmp->d = tmp->c;
	tmp->c = tmp->b;
	tmp->b = tmp->a;
	tmp->a = tmp->t1 + tmp->t2;
}

static void					main_sha_cicle(t_sha_data512 *tmp,\
		unsigned long long int *w)
{
	int						i;

	i = -1;
	while (++i < 80)
	{
		tmp->z0 = rotr512(tmp->a, 28) ^ rotr512(tmp->a, 34)
			^ rotr512(tmp->a, 39);
		tmp->ma = (tmp->a & tmp->b) ^ (tmp->a & tmp->c) ^
			(tmp->b & tmp->c);
		tmp->t2 = tmp->z0 + tmp->ma;
		tmp->z1 = rotr512(tmp->e, 14) ^ rotr512(tmp->e, 18) ^
			rotr512(tmp->e, 41);
		tmp->ch = (tmp->e & tmp->f) ^ ((~tmp->e) & tmp->g);
		tmp->t1 = tmp->h + tmp->z1 + tmp->ch + g_k1[i] + w[i];
		add_data(tmp);
	}
	tmp->h0 += tmp->a;
	tmp->h1 += tmp->b;
	tmp->h2 += tmp->c;
	tmp->h3 += tmp->d;
	tmp->h4 += tmp->e;
	tmp->h5 += tmp->f;
	tmp->h6 += tmp->g;
	tmp->h7 += tmp->h;
}

static void					init_add_array(unsigned long long int *w, \
		unsigned long long int *tmp, int i)
{
	int						j;
	unsigned long long int	s0;
	unsigned int long long	s1;

	j = -1;
	while (++j < 16)
		w[j] = tmp[i++];
	while (j < 80)
	{
		s0 = rotr512(w[j - 15], 1) ^ rotr512(w[j - 15], 8) ^
			(w[j - 15] >> 7);
		s1 = rotr512(w[j - 2], 19) ^ rotr512(w[j - 2], 61) ^
			(w[j - 2] >> 6);
		w[j] = w[j - 16] + s0 + w[j - 7] + s1;
		j++;
	}
}

void						create_hash_sha512(unsigned long long int *tmp,\
		int len, t_alg *alg)
{
	t_sha_data512			*data;
	int						i;
	unsigned long long int	*w;

	i = 0;
	w = (unsigned long long int *)malloc(sizeof(unsigned long long int) * 80);
	data = (t_sha_data512 *)malloc(sizeof(t_sha_data512));
	init_data(data);
	while (i < len / 8)
	{
		init_data512(data);
		init_add_array(w, tmp, i);
		main_sha_cicle(data, w);
		i += 16;
	}
	free(w);
	ft_printf("%02llx%02llx%02llx%02llx%02llx%02llx%02llx%02llx",\
			data->h0, data->h1, data->h2, data->h3, data->h4,\
			data->h5, data->h6, data->h7);
	free(data);
	if (!alg->r)
		ft_printf("\n");
}