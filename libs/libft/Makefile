# **************************************************************************** #
#                                                          :::      ::::::::   #
#   ft_strcut.c                                          :+:      :+:    :+:   #
#                                                      +:+ +:+         +:+     #
#   By: gugrug <gustavorugg@gmail.com>               +#+  +:+       +#+        #
#                                                  +#+#+#+#+#+   +#+           #
#                                                       #+#    #+#             #
#                                                      ###   ########          #
# **************************************************************************** #

############################ MY OWN BASIC C LIBRARY ############################

# Name of the executable file
NAME				=	libft.a

# C Compiler configuration
CC					=	clang
CC_FLAGS			=	$(BASIC_FLAGS) #$(CC_TESTS)
BASIC_FLAGS			=	-Wall -Wextra -Werror
CC_TESTS			=	-g #-fsanitize=address

# Location of the dependencies used
SRCS_DIR			=	./srcs
OBJS_DIR			=	./objs
INCS_DIR			=	./include
DIR_SRCS_GNL		=	$(SRCS_DIR)/gnl
DIR_SRCS_IS			=	$(SRCS_DIR)/is
DIR_SRCS_LST		=	$(SRCS_DIR)/lst
DIR_SRCS_MEM		=	$(SRCS_DIR)/mem
DIR_SRCS_PUT		=	$(SRCS_DIR)/put
DIR_SRCS_STR		=	$(SRCS_DIR)/str
DIR_SRCS_TO			=	$(SRCS_DIR)/to
DIR_SRCS_UTILS		=	$(SRCS_DIR)/utils

# Libraries and its location
INCLUDE				=	-I$(INCS_DIR)

# Compact to SRCS
SRCS				=	$(SRCS_GNL)										\
						$(SRCS_IS)										\
						$(SRCS_LST)										\
						$(SRCS_MEM)										\
						$(SRCS_PUT)										\
						$(SRCS_STR)										\
						$(SRCS_TO)										\
						$(SRCS_UTILS)

# Sources
SRCS_GNL			=	$(DIR_SRCS_GNL)/ft_get_next_line.c

SRCS_IS				=	$(DIR_SRCS_IS)/ft_isalpha.c						\
						$(DIR_SRCS_IS)/ft_isdigit.c						\
						$(DIR_SRCS_IS)/ft_isalnum.c						\
						$(DIR_SRCS_IS)/ft_isascii.c						\
						$(DIR_SRCS_IS)/ft_isprint.c

SRCS_LST			=	$(DIR_SRCS_LST)/ft_lstnew.c						\
						$(DIR_SRCS_LST)/ft_lstadd_front.c				\
						$(DIR_SRCS_LST)/ft_lstsize.c					\
						$(DIR_SRCS_LST)/ft_lstlast.c					\
						$(DIR_SRCS_LST)/ft_lstadd_back.c				\
						$(DIR_SRCS_LST)/ft_lstdelone.c					\
						$(DIR_SRCS_LST)/ft_lstclear.c					\
						$(DIR_SRCS_LST)/ft_lstiter.c					\
						$(DIR_SRCS_LST)/ft_lstmap.c

SRCS_MEM			=	$(DIR_SRCS_MEM)/ft_memcpy.c						\
						$(DIR_SRCS_MEM)/ft_memccpy.c					\
						$(DIR_SRCS_MEM)/ft_memset.c						\
						$(DIR_SRCS_MEM)/ft_memmove.c					\
						$(DIR_SRCS_MEM)/ft_memchr.c						\
						$(DIR_SRCS_MEM)/ft_memcmp.c

SRCS_PUT			=	$(DIR_SRCS_PUT)/ft_putchar_fd.c					\
						$(DIR_SRCS_PUT)/ft_putstr_fd.c					\
						$(DIR_SRCS_PUT)/ft_putendl_fd.c					\
						$(DIR_SRCS_PUT)/ft_putnbr_fd.c

SRCS_STR			=	$(DIR_SRCS_STR)/ft_strchr.c						\
						$(DIR_SRCS_STR)/ft_strrchr.c					\
						$(DIR_SRCS_STR)/ft_strnstr.c					\
						$(DIR_SRCS_STR)/ft_strlcat.c					\
						$(DIR_SRCS_STR)/ft_strlcpy.c					\
						$(DIR_SRCS_STR)/ft_strncmp.c					\
						$(DIR_SRCS_STR)/ft_strlen.c						\
						$(DIR_SRCS_STR)/ft_strdup.c						\
						$(DIR_SRCS_STR)/ft_strjoin.c					\
						$(DIR_SRCS_STR)/ft_strtrim.c					\
						$(DIR_SRCS_STR)/ft_strmapi.c					\
						$(DIR_SRCS_STR)/ft_strchr_bn.c					\
						$(DIR_SRCS_STR)/ft_substr.c						\
						$(DIR_SRCS_STR)/ft_strstr.c						\
						$(DIR_SRCS_STR)/ft_strcut.c

SRCS_TO				=	$(DIR_SRCS_TO)/ft_toupper.c						\
						$(DIR_SRCS_TO)/ft_tolower.c						\
						$(DIR_SRCS_TO)/ft_atoi.c						\
						$(DIR_SRCS_TO)/ft_itoa.c

SRCS_UTILS			=	$(DIR_SRCS_UTILS)/ft_bzero.c					\
						$(DIR_SRCS_UTILS)/ft_calloc.c					\
						$(DIR_SRCS_UTILS)/ft_split.c

# OBJS
SUBDIRS				=	gnl is lst mem put str to utils
DIR_OBJS			=	$(foreach dir, $(SUBDIRS),						\
						$(addprefix $(OBJS_DIR)/, $(dir)))
OBJS				=	$(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.o))

# RULES
all: $(NAME)

$(NAME):	$(OBJS)
			@ar -rcs $(NAME) $(OBJS)
			@ranlib $(NAME)
			@echo "libft is ready to use!"

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c
			@echo "Making libft . . ."
			@mkdir -p $(OBJS_DIR) $(DIR_OBJS)
			@$(CC) $(CC_FLAGS) $(INCLUDE) -c $< -o $@

clean:
			@echo "Cleaning libft . . ."
			@rm -r $(OBJS_DIR)
			@echo "libft has been cleaned!"

name_clean:
			@echo "Removing $(NAME) . . ."
			@rm -f $(NAME)
			@echo "$(NAME) was removed successfully!"

fclean: name_clean clean

re: fclean all

.PHONY: all clean fclean name_clean re
