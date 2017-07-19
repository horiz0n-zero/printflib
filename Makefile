# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afeuerst <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/19 14:24:52 by afeuerst          #+#    #+#              #
#    Updated: 2017/07/19 14:32:50 by afeuerst         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf

C_SRC = $(shell find . -type f | grep "\.c")
O_SRC = $(C_SRC:.c.o)

FLAGS = -O0 -fsanitize=address

all:
	make -j $(NAME)

$(NAME): $(O_SRC)
	clang $(FLAGS) $(O_SRC) -o $(NAME)

%.c.o:
	clang $(FLAGS) $< -o $@

clean:
	rm -r $(O_SRC)

fclean: clean
	rm -r $(NAME)

re: fclean all
