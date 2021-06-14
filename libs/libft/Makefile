# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/03 18:56:21 by gumartin          #+#    #+#              #
#    Updated: 2021/06/13 23:39:16 by gumartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memset.c ft_memmove.c ft_memchr.c \
	ft_memcmp.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strnstr.c \
	ft_strlcat.c ft_strlcpy.c ft_strncmp.c ft_strlen.c ft_atoi.c ft_calloc.c \
	ft_strdup.c \
	ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c \
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c ft_strchr_bn.c \
	get_next_line.c
SRCS_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)
$(NAME): $(SRCS) libft.h
	gcc $(FLAGS) -c $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

bonus: $(OBJS) $(OBJS_BONUS)
	ar rc $(NAME) $(OBJS) $(OBJS_BONUS)
	ranlib $(NAME)

#bonus:
#	gcc $(FLAGS) -c $(SRCS) $(SRCS_BONUS)
#	ar rc $(NAME) $(OBJS) $(OBJS_BONUS)
#	ranlib $(NAME)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
