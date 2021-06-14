# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/06 08:13:04 by gumartin          #+#    #+#              #
#    Updated: 2021/06/13 19:53:29 by gumartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the executable file
NAME		=	miniRT

# Files needed to build this project
SRCS_FILES	=	main.c	\
				TESTE.c	\
				color.c	\
				draw.c	\
				hook.c	\
				elem.c	\
				scene.c	\

# Location of the dependencies used
SRCS_DIR	=	./srcs
OBJS_DIR	=	./objs
INCS_DIR	=	./include
MLX_DIR		=	./libs/minilibx
FT_DIR		=	./libs/libft
X_DIR		=	/usr/include

# C Compiler configuration
CC			=	gcc
CC_FLAGS	=	-Wall -Wextra -Werror

# Libraries and its location
LIBFT		=	libft.a
LIBMLX		=	libmlx.a
LIBS_DIR_ALL=	-L$(X_DIR) -L$(MLX_DIR) -L$(FT_DIR)
LIBS_ALL	=	-lbsd -lmlx -lXext -lX11 -lm -lft
INCS_ALL	=	-I$(INCS_DIR) -I$(MLX_DIR) -I$(FT_DIR)

# Apply path to source files and object ones
SRCS		=	$(patsubst %.c, $(SRCS_DIR)/%.c, $(SRCS_FILES))
OBJS		=	$(patsubst %.c, $(OBJS_DIR)/%.o, $(SRCS_FILES))

all:	$(FT_DIR)/$(LIBFT) $(MLX_DIR)/$(LIBMLX) $(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CC_FLAGS) $^ $(LIBS_DIR_ALL) $(LIBS_ALL) -o $@

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CC_FLAGS) $(INCS_ALL) -c $< -o $@

$(FT_DIR)/$(LIBFT):
	@echo "Making libft . . ."
	@$(MAKE) -C $(FT_DIR) all
	@echo "libft is ready to use!"

$(MLX_DIR)/$(LIBMLX):
	@echo "Making libmlx . . ."
	@$(MAKE) -C $(MLX_DIR) all
	@echo "libmlx is ready to use!"

clean:
	@echo "Cleaning libft . . ."
	@$(MAKE) -C $(FT_DIR) clean
	@echo "libft has been cleaned!"
	@echo "Removing object files [.obj] . . ."
	$(RM) -r $(OBJS_DIR)
	@echo "Object files were removed successfully!"

fclean:	clean
	@echo "Cleaning libmlx . . ."
	@$(MAKE) -C $(MLX_DIR) clean
	@echo "libmlx has been cleaned!"
	@echo "Full cleaning libft . . ."
	@$(MAKE) -C $(FT_DIR) fclean
	@echo "libft has been cleaned thoroughly!"
	@echo "Removing $(NAME) . . ."
	$(RM) $(NAME)
	@echo "$(NAME) was removed successfully!"

re:	fclean all

.PHONY:	all clean fclean re

# NAME		=	miniRT

# LIB_DIR		=	./lib
# MLX_DIR		=	${LIB_DIR}/minilibx
# LIBFT_DIR	=	${LIB_DIR}/libft

# MLX			=	${MLX_DIR}/libmlx_Linux.a
# LIBFT		=	${LIBFT_DIR}/libft.a
# MODULES		=	$(LIB_DIR) $(MLX_DIR)

# CC			=	gcc

# CC_FLAGS	=	-c -Wall -Wextra -Werror	\
# 				-I${MLX_DIR}	\
# 				-I${LIBFT_DIR}	\
# 				-I${INCLUDE_DIR}

# ML_FLAGS	=	-L${LIBFT_DIR}		\
# 				-L${MLX_DIR}		\
# 				-lm					\
# 				-lft				\
# 				-lmlx_Linux			\
# 				-lXext				\
# 				-lX11

# INCLUDE_DIR	=	./include
# SRC_DIR		=	./src
# OBJ_DIR		=	./obj

# SRC			= 	${SRC_DIR}/main.c	\
# OBJ			=	$(patsubst %.c, %.o, ${SRC})


# all: $(NAME)

# $(NAME): $(OBJ)
# 	$(CC) $^ $(ML_FLAGS) -o $@

# $(LIBFT):
# 	$(MAKE) -C $(LIBFT_DIR)
# $(MLX):
# 	$(MAKE) -C $(MLX_DIR)


# $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c ${LIBFT} ${MLX}
# 	mkdir -p $(OBJ_DIR)
# 	$(CC) $(CC_FLAG) $(INCLUDE) $< -o $@

# clean:
# 	for dir in $(MODULES); do	\
# 		$(MAKE) clean -C $$dir;	\
# 	done
# 	rm -f $(OBJ)

# fclean: clean
# 	@$(MAKE) fclean -C $(LIB_DIR)
# 	rm -f $(NAME)

# re: fclean all

#valg: batata
#	valgrind --leak-check=full ./a.out

.PHONY: all clean fclean re
