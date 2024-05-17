# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iecer <iecer@student.42kocaeli.com.tr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 12:10:59 by iecer             #+#    #+#              #
#    Updated: 2024/03/14 12:11:00 by iecer            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C = client
NAME_S = server
FLAGS = -Wall -Wextra -Werror
FILE1 = client.c
FILE2 = server.c
CC = cc

all: $(NAME_C) $(NAME_S)

$(NAME_C): $(FILE1)
	$(CC) $(FLAGS) $(FILE1) -o $(NAME_C)

$(NAME_S): $(FILE2)
	$(CC) $(FLAGS) $(FILE2) -o $(NAME_S)

clean:
	rm -f server
	rm -f client

fclean:
	rm -f $(NAME_C)
	rm -f $(NAME_S)

re: fclean all

.PHONY: all clean fclean re
