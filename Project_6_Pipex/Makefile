# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppitzini <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 16:43:36 by ppitzini          #+#    #+#              #
#    Updated: 2024/01/25 16:43:39 by ppitzini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC 	   = ft_printf \
			 ft_putchar \
			 ft_putnbr \
			 ft_putnbr_base \
			 ft_putstr \
			 error_utils \
			 pipe_creation \
			 pipex_utils_two \
			 pipex_utils \
			 pipex_verifs \
			 pipex \


CC	= gcc

CFLAGS	= -Wall -Wextra -Werror -g

EXEC	= pipex

CFILES	= $(SRC:%=%.c)

OBJ	= $(SRC:=.o)

NAME = $(EXEC)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
