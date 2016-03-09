#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcourrie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/23 16:16:15 by gcourrie          #+#    #+#              #
#    Updated: 2016/03/09 13:35:50 by gcourrie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=		libftprintf.a

SRC_PATH=		./sources/

OBJ_PATH=		./objects/

SRC_NAME=		ft_printf.c \
				ft_width.c \
				ft_printf_fonctions_1.c \
				ft_printf_fonctions_2.c \
				ft_printf_fonctions_3.c \
				ft_putchar.c \
				ft_putstr.c \
				ft_putstr_len.c \
				ft_strcpy.c \
				ft_strncpy.c \
				ft_strdup.c \
				ft_memset.c \
				ft_bzero.c \
				ft_atoi.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_memalloc.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memcpy.c \
				ft_memdel.c \
				ft_memmove.c \
				ft_putchar_fd.c \
				ft_putnbr.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_strcat.c \
				ft_strchr.c \
				ft_strclr.c \
				ft_strcmp.c \
				ft_strdel.c \
				ft_strlen.c \
				ft_strncat.c \
				ft_strncmp.c \
				ft_strnew.c \
				ft_strrchr.c \
				ft_strstr.c \
				ft_strnstr.c \
				ft_strlcat.c \
				ft_memcmp.c \
				ft_strtrim.c \
				ft_strsub.c \
				ft_strsplit.c \
				ft_strjoin.c \
				ft_striteri.c \
				ft_striter.c \
				ft_putendl.c \
				ft_putendl_fd.c \
				ft_itoa.c \
				ft_strmap.c \
				ft_strmapi.c \
				ft_strequ.c \
				ft_strnequ.c \
				ft_lstnew.c \
				ft_lstdelone.c \
				ft_lstdel.c \
				ft_lstadd.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_itoa_base.c \
				ft_strndup.c \
				ft_strjoin_free.c \
				ft_strjoin_free_len.c \
				va_arg_extraction.c

INC_PATH=		./includes/

CFLAGS	=		-Wall -Wextra -Werror

GCC		=		gcc

OBJ_NAME=		$(SRC_NAME:.c=.o)

SRC		=		$(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ		=		$(addprefix $(OBJ_PATH),$(OBJ_NAME))

INC		=		$(addprefix -I,$(INC_PATH))

all:			$(NAME)

$(NAME):		$(OBJ)
				ar rc $(NAME) $(OBJ)
				ranlib $(NAME)
				$(GCC) $(CFLAGS) -o printf main.c libftprintf.a

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c
				@mkdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
				$(GCC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
				rm -vf $(OBJ) $(OBJ2)
				@rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null

fclean:			clean
				rm -vf $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
