# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/14 15:50:28 by mbourand          #+#    #+#              #
#    Updated: 2020/02/06 13:42:56 by mbourand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3d
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
SRC_PATH= srcs/
OBJ_PATH= objs/

SRC_NAME= main.c parser.c parserutils.c ray.c utils.c ft_numberlen.c \
			get_next_line.c get_next_line_utils.c ft_skipcharset.c \
			ft_endswith.c ft_strdel.c ft_onlypattern.c check_map.c \
			mathutils.c key_event.c close_event.c render.c ft_inrange.c \
			image.c camera.c map.c render_wall.c render_sprite.c
OBJ_NAME= $(SRC_NAME:.c=.o)

INC= -I incs/ -I libft/
SRC= $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ= $(addprefix $(OBJ_PATH), $(OBJ_NAME))
LIB= -L libft/ -lft -lm -L/usr/X11/lib /usr/X11/lib/libmlx.a -lXext -lX11

DEF= \033[0m
RED= \033[31;1m
GRN= \033[32;1m
YEL= \033[33;1m

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(RED)[cub3d] : $(DEF)Compilation..."
	@make -C libft
	@gcc $(CFLAGS) -fsanitize=address -o $(NAME) $(OBJ) $(INC) $(LIB)
	@echo "$(RED)[cub3d] : $(DEF)Compilation                 $(GRN)[OK]$(DEF)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@echo "$(RED)[cub3d] :$(DEF) Compiling $@"
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	@make -C libft clean
	@rm -rf $(OBJ_PATH)
	@echo "$(RED)[cub3d] : $(DEF)Cleaning           $(GRN)[OK]$(DEF)"

fclean: clean
	@make -C libft fclean
	@rm -rf $(NAME)
	@echo "$(RED)[cub3d] : $(DEF)Full Cleaning       $(GRN)[OK]$(DEF)"

re: fclean all
