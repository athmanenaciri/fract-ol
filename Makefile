# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anaciri <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/13 20:45:47 by anaciri           #+#    #+#              #
#    Updated: 2022/03/28 14:01:41 by anaciri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 

CFLAGS = -Wall -Werror -Wextra

LDFLAGS = -lmlx -framework OpenGL -framework AppKit

OBJ = main.o utils.o event.o zoom.o utils_extra.o 

NAME = fractol

all: $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

re: fclean all
