/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdrakh <aabdrakh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 12:26:51 by aabdrakh          #+#    #+#             */
/*   Updated: 2019/06/19 22:15:26 by aabdrakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ssl.h"

int		main(int argc, char **argv)
{
	t_data m;

	init_flags(&m);
	if (argc <= 1)
		error_usage(1);
	argv[1] = str_lower(argv[1]);
	if (!ft_strcmp(argv[1], "sha256")
		|| !ft_strcmp(argv[1], "md5")
		|| !ft_strcmp(argv[1], "sha512"))
	{
		if (argc < 3)
			case_no_arg(argv[1], m, 0);
		else
		{
			while (argv[m.arg] && argv[m.arg][0] == '-')
				case_flags(argv[1], &m, argv[m.arg], argv[m.arg + 1]);
			if (!argv[m.arg] && ft_strchr("qr", argv[m.arg - 1][1]))
				case_no_arg(argv[1], m, 0);
		}
		while (m.arg < argc)
			case_arg(argv[1], argv[m.arg++], m, m.flags[1]);
	}
	else
		error_usage(1);
	return (0);
}

void	init_flags(t_data *m)
{
	m->flags[0] = 2;
	m->flags[1] = 1;
	m->arg = 2;
}

void	case_flags(char *comand, t_data *m,
	char *arg, char *nextarg)
{
	m->i = 0;
	while (arg && arg[++m->i] && ft_strchr("pqrs", arg[m->i]))
	{
		if (arg[m->i] == 'r' && m->flags[0] != 0)
		{
			m->flags[0] = 4;
			m->flags[1] = 3;
		}
		else if (arg[m->i] == 'q')
		{
			m->flags[0] = 0;
			m->flags[1] = 0;
		}
		else if (arg[m->i] == 'p')
			case_no_arg(comand, *m, 5);
		else if (arg[m->i] == 's')
		{
			case_string(comand, nextarg, *m, m->flags[0]);
			m->arg++;
		}
	}
	if (arg && arg[m->i] != '\0')
		error_usage(2);
	m->arg++;
}
