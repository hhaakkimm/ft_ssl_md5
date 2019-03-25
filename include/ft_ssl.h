/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 16:02:54 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/03/24 22:19:48 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include <stdint.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "ft_printf.h"

# define ROTR64(x, n)	(((x >> n) | (x << (32 - n))))
# define ROTL(val, shift)	(((val << shift) | (val >> (32 - shift))))
# define ROTR(val, shift)	(val >> shift)
# define MAJ(x,y,z) ((x & y) ^ (x & z) ^ (y & z))
# define CH(x,y,z) ((x & y) ^ ((~x) & z))
# define E0(x)	(ROTR64(x, 2) ^ ROTR64(x, 13) ^ ROTR64(x, 22))
# define E1(x)	(ROTR64(x, 6) ^ ROTR64(x, 11) ^ ROTR64(x, 25))
# define S0(x)	(ROTR64(x, 7) ^ ROTR64(x, 18) ^ ROTR(x, 3))
# define S1(x)	(ROTR64(x, 17) ^ ROTR64(x, 19) ^ ROTR(x, 10))

# define BUFFSIZE	(int)(5 * 1e5)

# define F(x,y,z) ((x & y) | ((~x) & z))
# define G(x,y,z) ((x & z) | (y & (~z)))
# define H(x,y,z) (x ^ y ^ z)
# define I(x,y,z) (y ^ (x | (~z)))

static unsigned long long int	g_k1[80] =
{
	0x428a2f98d728ae22, 0x7137449123ef65cd, 0xb5c0fbcfec4d3b2f,
	0xe9b5dba58189dbbc, 0x3956c25bf348b538, 0x59f111f1b605d019,
	0x923f82a4af194f9b, 0xab1c5ed5da6d8118, 0xd807aa98a3030242,
	0x12835b0145706fbe, 0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2,
	0x72be5d74f27b896f, 0x80deb1fe3b1696b1, 0x9bdc06a725c71235,
	0xc19bf174cf692694, 0xe49b69c19ef14ad2, 0xefbe4786384f25e3,
	0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65, 0x2de92c6f592b0275,
	0x4a7484aa6ea6e483, 0x5cb0a9dcbd41fbd4, 0x76f988da831153b5,
	0x983e5152ee66dfab, 0xa831c66d2db43210, 0xb00327c898fb213f,
	0xbf597fc7beef0ee4, 0xc6e00bf33da88fc2, 0xd5a79147930aa725,
	0x06ca6351e003826f, 0x142929670a0e6e70, 0x27b70a8546d22ffc,
	0x2e1b21385c26c926, 0x4d2c6dfc5ac42aed, 0x53380d139d95b3df,
	0x650a73548baf63de, 0x766a0abb3c77b2a8, 0x81c2c92e47edaee6,
	0x92722c851482353b, 0xa2bfe8a14cf10364, 0xa81a664bbc423001,
	0xc24b8b70d0f89791, 0xc76c51a30654be30, 0xd192e819d6ef5218,
	0xd69906245565a910, 0xf40e35855771202a, 0x106aa07032bbd1b8,
	0x19a4c116b8d2d0c8, 0x1e376c085141ab53, 0x2748774cdf8eeb99,
	0x34b0bcb5e19b48a8, 0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb,
	0x5b9cca4f7763e373, 0x682e6ff3d6b2b8a3, 0x748f82ee5defb2fc,
	0x78a5636f43172f60, 0x84c87814a1f0ab72, 0x8cc702081a6439ec,
	0x90befffa23631e28, 0xa4506cebde82bde9, 0xbef9a3f7b2c67915,
	0xc67178f2e372532b, 0xca273eceea26619c, 0xd186b8c721c0c207,
	0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178, 0x06f067aa72176fba,
	0x0a637dc5a2c898a6, 0x113f9804bef90dae, 0x1b710b35131c471b,
	0x28db77f523047d84, 0x32caab7b40c72493, 0x3c9ebe0a15c9bebc,
	0x431d67c49c100d4c, 0x4cc5d4becb3e42b6, 0x597f299cfc657e2a,
	0x5fcb6fab3ad6faec, 0x6c44198c4a475817
};

typedef struct					s_sha_data512
{
	unsigned long long int		a;
	unsigned long long int		b;
	unsigned long long int		c;
	unsigned long long int		d;
	unsigned long long int		e;
	unsigned long long int		f;
	unsigned long long int		g;
	unsigned long long int		h;
	unsigned long long int		h0;
	unsigned long long int		h1;
	unsigned long long int		h2;
	unsigned long long int		h3;
	unsigned long long int		h4;
	unsigned long long int		h5;
	unsigned long long int		h6;
	unsigned long long int		h7;
	unsigned long long int		z0;
	unsigned long long int		ma;
	unsigned long long int		t2;
	unsigned long long int		z1;
	unsigned long long int		ch;
	unsigned long long int		t1;
}								t_sha_data512;

typedef struct				s_alg
{
	int						cript;
	int						r;
	int						p;
	int						q;
	int						s;
	int						std;
	unsigned char			*str;
}							t_alg;

typedef struct      			s_flags{
	int							p;
	int							q;
	int							r;
	int							s;
}								t_flags;

typedef enum		e_type
{
	md5,
	sha256,
	sha512
}					t_type;

typedef struct		s_hash
{
	uint32_t		h[8];
}					t_hash;

typedef struct		s_reg
{
	uint32_t		el[11];
}					t_reg;

typedef struct		s_data
{
	size_t			sz;
	unsigned char	*word;
	char			*message;
	int				flags[2];
	int				arg;
	int				i;
}					t_data;

typedef void		(*t_fct) (char *, t_data *);

typedef struct		s_dispatch
{
	int				command;
	t_fct			fct;
}					t_dispatch;

void				error_usage(int type);
uint32_t			ft_binpow(uint32_t a, int n);
float				ft_abs(float x);
char				*ft_itoa_base(int64_t value, int base);
void				ft_sha256(char *str, t_data *m);
void				ft_blocks_sha256(unsigned char *padded, t_hash *h);
void				ft_mainloop_sha256(t_hash *h, uint32_t *m);
void				ft_rotation_sha256(t_reg r, t_hash *h,
	uint32_t *k, uint32_t *w);
uint32_t			*ft_reg_sha256(void);

void				ft_md5(char *str, t_data *m);
void				ft_blocks_md5(unsigned char *padded, t_hash *h);
void				ft_rotation_md5(t_reg *r, uint32_t *m,
	uint32_t *k, uint32_t *s);
void				ft_mainloop_md5(t_hash *h, uint32_t *m);
uint32_t			*ft_reg_md5(void);

void				ft_data_sha256(char *str, t_data *m);
void				ft_data_new(t_data *m, t_hash h, int len_hash);
void				ft_data_md5(char *str, t_data *m);

uint64_t			swap_uint64(uint64_t val);
uint32_t			swap_uint32(uint32_t val);

char				*ft_fd_to_str(int fd);
char				*str_upper(char *str);
char				*str_lower(char *str);
int					ft_validfile(char *comand, char *arg);

void				init_flags(t_data *m);
void				ft_error(char *comand, char option, int flag);
void				case_flags(char *comand, t_data *m,
	char *argument, char *nextarg);

void				ft_printhash(char *str, char *comand,
	t_data m, char flags);
char				*ft_command(char *comand, t_data *m, int fd);
void				case_no_arg(char *comand, t_data m, char flags);
void				case_arg(char *comand, char *arg,
	t_data m, char flags);
void				case_string(char *comand, char *str,
	t_data m, char flags);

#endif
