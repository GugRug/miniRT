# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/06 08:13:04 by gumartin          #+#    #+#              #
#    Updated: 2021/04/12 08:40:14 by gumartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	miniRT

LIB_DIR		=	./lib
MLX_DIR		=	${LIB_DIR}/minilibx
LIBFT_DIR	=	${LIB_DIR}/libft

MLX			=	${MLX_DIR}/libmlx_Linux.a
LIBFT		=	${LIBFT_DIR}/libft.a
MODULES		=	$(LIB_DIR) $(MLX_DIR)

CC			=	gcc

CC_FLAGS	=	-c -Wall -Wextra -Werror	\
				-I${MLX_DIR}	\
				-I${LIBFT_DIR}	\
				-I${INCLUDE_DIR}

ML_FLAGS	=	-L${LIBFT_DIR}		\
				-L${MLX_DIR}		\
				-lm					\
				-lft				\
				-lmlx_Linux			\
				-lXext				\
				-lX11

INCLUDE_DIR	=	./include
SRC_DIR		=	./src
OBJ_DIR		=	./obj

SRC			= 	${SRC_DIR}/main.c	\
OBJ			=	$(patsubst %.c, %.o, ${SRC})


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $^ $(ML_FLAGS) -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
$(MLX):
	$(MAKE) -C $(MLX_DIR)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c ${LIBFT} ${MLX}
	mkdir -p $(OBJ_DIR)
	$(CC) $(CC_FLAG) $(INCLUDE) $< -o $@

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

.PHONY: all clean fclean re
