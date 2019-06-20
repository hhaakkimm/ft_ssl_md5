# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabdrakh <aabdrakh@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/22 12:14:43 by aabdrakh          #+#    #+#              #
#    Updated: 2019/06/19 22:08:50 by aabdrakh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_ssl
SRC	= src/ft_sha256.c\
					src/ft_md5.c\
					src/ft_message.c\
					src/ft_help.c\
					src/ft_main.c\
					src/ft_cases.c\
					src/ft_util.c\
					src/ft_util2.c



HEADER	= -I ./include/ft_ssl.h
LIB		= ./include/libftprintf.a

$(NAME): $(SRC)
	@gcc -Wall -Wextra -Werror -o $(NAME) $(SRC) $(HEADER) $(LIB)

all: $(NAME)

clean:
	@rm -rf $(NAME)*

fclean: clean

re: fclean $(NAME)
