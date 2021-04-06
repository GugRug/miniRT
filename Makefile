# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/06 08:13:04 by gumartin          #+#    #+#              #
#    Updated: 2021/04/06 08:37:47 by gumartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	miniRT

LIB_DIR		=	./lib

MLX_DIR		=	${LIB_DIR}/minilibx
MLX			=	${MLX_DIR}/libmlx_Linux.a

LIBFT_DIR	=	${LIB_DIR}/libft
LIBFT		=	${LIBFT_DIR}/libft.a

CC			=	gcc
FLAGS		=	-c -Wall -Wextra -Werror\
				-I${MLX_DIR} -I${LIBFT_DIR}

SRC_DIR	=	./src
SRC		= 	${SRC_DIR}/ft_c_print.c\
				./ft_u_print.c\
				./ft_s_print.c\
				./ft_utils.c\
				./ft_utils_2.c\
				./ft_flags.c\
				./ft_flags_2.c\
				./ft_p_print.c\
				./ft_putnbr.c\
				./ft_di_print.c\
				./ft_x_print.c\
				./ft_pct_print.c\
				./ft_printf.c\
				./ft_clean.c

OBJ = $(SRC:.c=.o)

all: $(NAME)
$(NAME): $(SRC) ft_printf.h
	$(CC) $(FLAGS) $(SRC)
	ar rc $(NAME) $(OB)
	ranlib $(NAME)

$(MLX):
	$(MAKE) -C $(MLX_DIR)
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

#batata:
#	gcc -g *.c  printf.h

#valg: batata
#	valgrind --leak-check=full ./a.out

.PHONY: all clean fclean re
