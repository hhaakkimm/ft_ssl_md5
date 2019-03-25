# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabdrakh <aabdrakh@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/22 12:14:43 by aabdrakh          #+#    #+#              #
#    Updated: 2019/03/24 22:33:51 by aabdrakh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_ssl
SRC	= ft_sha256.c\
					ft_md5.c\
					ft_message.c\
					ft_help.c\
					ft_main.c\
					ft_cases.c\
					ft_util.c\
					ft_util2.c



HEADER	= -I ./include/ft_ssl.h
LIB		= ./include/libftprintf.a

$(NAME): $(SRC)
	@gcc -Wall -Wextra -Werror -o $(NAME) $(SRC) $(HEADER) $(LIB)

all: $(NAME)

clean:
	@rm -rf $(NAME)*

fclean: clean

re: fclean $(NAME)
