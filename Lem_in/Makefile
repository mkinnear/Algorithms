# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkinnear <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/09 21:23:52 by mkinnear          #+#    #+#              #
#    Updated: 2017/12/09 21:24:31 by mkinnear         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC =	srcs/lemin.c\
		srcs/room.c\
		srcs/links.c\
		srcs/ant.c\
		srcs/weighing.c\
		srcs/weighing2.c\
		srcs/ft_freelemin.c\
		srcs/ft_validation.c\
		srcs/move.c\
		srcs/move_helper.c\
		srcs/links_helper.c\
		srcs/get_type.c\
		srcs/room2.c

OBJ =	lemin.o\
		room.o\
		links.o\
		ant.o\
		weighing.o\
		weighing2.o\
		ft_freelemin.o\
		ft_validation.o\
		move.o\
		move_helper.o\
		links_helper.o\
		get_type.o\
		room2.o

LIBFT = ./libft

FLAGS = -Wall\
		-Wextra\
		-Werror

all: $(NAME)

$(NAME):
		@make -C $(LIBFT)
		@gcc -c $(FLAGS) $(SRC)
		@gcc -o $(NAME) $(FLAGS) $(OBJ) -L$(LIBFT) -lft

clean:
		@rm -f $(OBJ)
		@cd ./libft && $(MAKE) clean

fclean: clean
		@rm -f $(NAME)
		@cd ./libft && $(MAKE) fclean

re: fclean all
