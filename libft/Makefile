# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/14 15:50:28 by mbourand          #+#    #+#              #
#    Updated: 2020/01/29 14:46:01 by mbourand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
SRC_PATH= ./
OBJ_PATH= objs/

SRC_NAME= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
			ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd_back.c \
			ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
			ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstnew.c ft_lstsize.c \
			ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
			ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c \
			ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
			ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
			ft_toupper.c ft_lstat.c
OBJ_NAME= $(SRC_NAME:.c=.o)

INC= -I .
SRC= $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ= $(addprefix $(OBJ_PATH), $(OBJ_NAME))

DEF= \033[0m
RED= \033[31;1m
GRN= \033[32;1m
YEL= \033[33;1m

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(RED)[libft] : $(DEF)Compilation..."
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(RED)[libft] : $(DEF)Compilation                 $(GRN)[OK]$(DEF)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@echo "$(RED)[libft] :$(DEF) Compiling $@"
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	@rm -rf $(OBJ_PATH)
	@echo "$(RED)[libft] : $(DEF)Cleaning           $(GRN)[OK]$(DEF)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)[libft] : $(DEF)Full Cleaning       $(GRN)[OK]$(DEF)"

re: fclean all
