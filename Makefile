# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/06 08:13:04 by gumartin          #+#    #+#              #
#    Updated: 2021/04/11 08:58:47 by gumartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	miniRT

CC			=	gcc

LIB_DIR		=	./lib
MLX_DIR		=	${LIB_DIR}/minilibx
MLX			=	${MLX_DIR}/libmlx_Linux.a
LIBFT_DIR	=	${LIB_DIR}/libft
LIBFT		=	${LIBFT_DIR}/libft.a
MODULES		=	$(LIB_DIR) $(MLX_DIR)

CC_FLAGS	=	-c -Wall -Wextra -Werror\
				-I${MLX_DIR} -I${LIBFT_DIR}
ML_FLAGS	=	-L${LIBFT_DIR}		\
				-L${LIBVECTOR_DIR}	\
				-L${MLX_DIR}		\
				-lm					\
				-lft				\
				-lmlx_Linux			\
				-lXext				\
				-lX11

SRC_DIR		=	./src
SRC			= 	${SRC_DIR}/ft_c_print.c\

OBJ_DIR		=	./obj
OBJ			=	${OBJ_DIR}/$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(SRC)
	$(CC) $^ $(LD_FLAGS) -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
$(MLX):
	$(MAKE) -C $(MLX_DIR)

%.o: %.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CC_FLAG) $< -o $@

clean:
	for dir in $(MODULES); do	\
		$(MAKE) clean -C $$dir;	\
	done
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C $(LIB_DIR)
	rm -f $(NAME)

re: fclean all

#valg: batata
#	valgrind --leak-check=full ./a.out

.PHONY: all clean fclean r
