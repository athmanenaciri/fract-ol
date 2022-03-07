# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anaciri <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/19 09:26:30 by anaciri           #+#    #+#              #
#    Updated: 2022/02/19 10:16:43 by anaciri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol 

SRC = try.c
LIB = fractol.h
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ) $(LIB)
	gcc $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME) 

%.o : %.c
	gcc -Imlx -c $< -o $@ $(CFLAGS)
	
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

re: fclean all
