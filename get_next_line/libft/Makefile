# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabdrakh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/16 14:02:05 by aabdrakh          #+#    #+#              #
#    Updated: 2018/09/22 12:34:40 by aabdrakh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_lstmap.c ft_putendl.c ft_strdup.c ft_strnequ.c	
SRC += ft_bzero.c ft_lstnew.c ft_putendl_fd.c ft_strequ.c ft_strnew.c	
SRC += ft_isalnum.c ft_memalloc.c ft_putnbr.c ft_striter.c ft_strnstr.c		
SRC += ft_isalpha.c ft_memccpy.c ft_putnbr_fd.c ft_striteri.c ft_strrchr.c	
SRC += ft_isascii.c ft_memchr.c ft_putstr.c ft_strjoin.c ft_strsplit.c	
SRC += ft_isdigit.c ft_memcmp.c ft_putstr_fd.c ft_strlcat.c ft_strstr.c	
SRC += ft_isprint.c ft_memcpy.c ft_strcat.c ft_strlen.c ft_strsub.c	
SRC += ft_itoa.c ft_memdel.c ft_strchr.c ft_strmap.c ft_strtrim.c	
SRC += ft_lstadd.c ft_memmove.c ft_strclr.c ft_strmapi.c ft_tolower.c	
SRC += ft_lstdel.c ft_memset.c ft_strcmp.c ft_strncat.c ft_toupper.c	
SRC += ft_lstdelone.c ft_putchar.c ft_strcpy.c ft_strncmp.c	
SRC += ft_lstiter.c ft_putchar_fd.c ft_strdel.c ft_strncpy.c

OBJECTS = *.o

INCLUDE = libft.h

all: $(NAME)

$(NAME):
	@gcc -c -Wall -Wextra -Werror $(SRC) -I $(INCLUDE)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
