# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/06 08:13:04 by gumartin          #+#    #+#              #
#    Updated: 2021/07/27 10:11:05 by gumartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the executable file
NAME				=	miniRT

# C Compiler configuration
CC					=	clang
CC_FLAGS			=	-Wall -Wextra -Werror
CC_TESTS			=	-g #-fsanitize=address

# Location of the dependencies used
SRCS_DIR			=	./srcs
DIR_SRCS_MAIN		=	$(SRCS_DIR)/main
DIR_SRCS_RAY		=	$(SRCS_DIR)/ray_trace
DIR_SRCS_RT			=	$(SRCS_DIR)/rt_file
DIR_SRCS_UTILS		=	$(SRCS_DIR)/utils
DIR_SRCS_VECTOR		=	$(SRCS_DIR)/vector
OBJS_DIR			=	./objs
INCS_DIR			=	./include
MLX_DIR				=	./libs/minilibx
FT_DIR				=	./libs/libft
X_DIR				=	/usr/include

# Libraries and its location
LIBFT				=	libft.a
LIBMLX				=	libmlx.a
LIBS_DIR_ALL		=	-L$(X_DIR) -L$(MLX_DIR) -L$(FT_DIR)
LIBS_ALL			=	-lbsd -lmlx -lXext -lX11 -lm -lft
INCS_ALL			=	-I$(INCS_DIR) -I$(MLX_DIR) -I$(FT_DIR)/include

# Sources
SRCS_MAIN			=	$(DIR_SRCS_MAIN)/bitmap.c					\
						$(DIR_SRCS_MAIN)/elem.c						\
						$(DIR_SRCS_MAIN)/error.c					\
						$(DIR_SRCS_MAIN)/main.c						\
						$(DIR_SRCS_MAIN)/scene.c

SRCS_RAY			=	$(DIR_SRCS_RAY)/camera.c					\
						$(DIR_SRCS_RAY)/canvas.c					\
						$(DIR_SRCS_RAY)/color.c						\
						$(DIR_SRCS_RAY)/hit.c						\
						$(DIR_SRCS_RAY)/ray.c						\
						$(DIR_SRCS_RAY)/raytrace.c

SRCS_RT				=	$(DIR_SRCS_RT)/rt_elem.c					\
						$(DIR_SRCS_RT)/rt_elem_obj.c				\
						$(DIR_SRCS_RT)/rt_file.c					\
						$(DIR_SRCS_RT)/validate.c

SRCS_UTILS			=	$(DIR_SRCS_UTILS)/clean.c					\
						$(DIR_SRCS_UTILS)/draw.c					\
						$(DIR_SRCS_UTILS)/hit_utils.c				\
						$(DIR_SRCS_UTILS)/hook.c					\
						$(DIR_SRCS_UTILS)/rt_elem_utils.c			\
						$(DIR_SRCS_UTILS)/validate_utils.c

SRCS_VECTOR			=	$(DIR_SRCS_VECTOR)/vector_2.c				\
						$(DIR_SRCS_VECTOR)/vector.c					\

# Compact to SRCS
SRCS 				=	$(SRCS_MAIN)								\
						$(SRCS_RAY)									\
						$(SRCS_RT)									\
						$(SRCS_UTILS)								\
						$(SRCS_VECTOR)

# OBJS
SUBDIRS				=	rt_file utils main vector ray_trace
DIR_OBJS			=	$(foreach dir, $(SUBDIRS),					\
						$(addprefix $(OBJS_DIR)/, $(dir)))
OBJS				=	$(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.o))

# RULES
all:	$(FT_DIR)/$(LIBFT) $(MLX_DIR)/$(LIBMLX) $(NAME)

$(NAME):	$(OBJS)
	@$(CC) $(CC_FLAGS) $(CC_TESTS) $^ $(LIBS_DIR_ALL) $(LIBS_ALL) -o $@
	@echo "miniRT is ready to use!"

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR) $(DIR_OBJS)
	@$(CC) $(CC_FLAGS) $(CC_TESTS) $(INCS_ALL) -c $< -o $@

$(FT_DIR)/$(LIBFT):
	@echo "Making libft . . ."
	@$(MAKE) -C $(FT_DIR) all
	@echo "libft is ready to use!"

$(MLX_DIR)/$(LIBMLX):
	@echo "Making libmlx . . ."
	@$(MAKE) -C $(MLX_DIR) all
	@echo "libmlx is ready to use!"

clean:
	@echo "Removing object files [.obj] . . ."
	@$(RM) -r $(OBJS_DIR)
	@echo "Object files were removed successfully!"

fclean:	clean
	@echo "Cleaning libmlx . . ."
	@$(MAKE) -C $(MLX_DIR) clean
	@echo "libmlx has been cleaned!"
	@echo "Full cleaning libft . . ."
	@$(MAKE) -C $(FT_DIR) fclean
	@echo "libft has been cleaned thoroughly!"
	@echo "Removing $(NAME) . . ."
	@$(RM) $(NAME)
	@echo "$(NAME) was removed successfully!"

valg:
	valgrind --leak-check=full ./miniRT examples/pokeball.rt

re:	fclean all

.PHONY: all clean fclean valg re
