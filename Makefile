# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dirony <dirony@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/05 20:08:26 by dirony            #+#    #+#              #
#    Updated: 2022/01/15 13:21:00 by dirony           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_B = checker

HEADER = push_swap.h

HEADER_B = bonus/push_swap_bonus.h 

SRC = 		main.c				list_utils.c\
			number_utils.c		error_utils.c\
			string_utils.c		error_utils2.c\
			sort_utils.c		operations1.c\
			sort_utils2.c		operations2.c\
			sort_utils3.c		ft_split.c\
			lis_utils.c			scoring_utils.c\
			stack_utils.c		array_utils.c\
			moving_utils.c

SRC_BONUS = bonus/main_bonus.c					bonus/list_utils_bonus.c\
			bonus/number_utils_bonus.c			bonus/error_utils_bonus.c\
			bonus/string_utils_bonus.c			bonus/error_utils2_bonus.c\
			bonus/get_next_line_bonus.c			bonus/operations1_bonus.c\
			bonus/stack_utils_bonus.c			bonus/operations2_bonus.c\
			bonus/parse_utils_bonus.c			bonus/ft_split_bonus.c\
										
OBJ = ${SRC:.c=.o}

OBJ_BONUS = ${SRC_BONUS:.c=.o}

CFLAGS = -Wall -Werror -Wextra -g

COMPILE = gcc $(CFLAGS)

REMOVE = rm -f

%.o 	:	%.c	$(HEADER)
			$(COMPILE) -c $< -o $@

.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(COMPILE) $(OBJ) -o $(NAME)

bonus:
	@make NAME="$(NAME_B)" OBJ="$(OBJ_BONUS)" HEADER="$(HEADER_B)" all

clean:
	@$(REMOVE) $(OBJ) $(OBJ_BONUS)

fclean: clean
	@$(REMOVE) $(NAME)

re: fclean all
