/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 19:22:29 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/03/24 21:45:46 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_ssl.h"

uint32_t		ft_binpow(uint32_t a, int n)
{
	uint32_t	res;

	res = 1;
	while (n)
	{
		if (n & 1)
			res *= a;
		a *= a;
		n >>= 1;
	}
	return (res);
}

float			ft_abs(float x)
{
	if (x < 0)
		x *= (-1);
	return (x);
}

void			error_usage(int type)
{
	if (type == 1)
		ft_printf("\nusage: ./ft_ssl command [command opts] [command args]\n\nStandard commands:\nMessage Digest commands:\nmd5\nsha256\n");
	if (type == 2)
		ft_printf("\nunknown flag\n\nAccepted flags: -p -q -r -s\n");
	if (type == 3)
		ft_printf("\nBad file\n");
	exit(0);
}