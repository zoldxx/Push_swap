# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dberreby <dberreby@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 11:38:53 by dberreby          #+#    #+#              #
#    Updated: 2023/02/06 12:09:57 by dberreby         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC				=	calcul_cout.c check_input.c find_low_high.c lst.c main.c \
					push_back.c push_cheapest.c push.c reverse_rotate.c rotate.c \
					swap.c tri_moins_de_5.c utils_stack.c utils.c utils2.c

OBJ 			=	$(SRC:.c=.o)

BONUS_SRC		=	checker.c checker_utils.c get_next_line.c get_next_line_utils.c \
					checker_utils2.c calcul_cout.c check_input.c find_low_high.c lst.c \
					push_back.c push_cheapest.c push.c reverse_rotate.c rotate.c \
					swap.c tri_moins_de_5.c utils_stack.c utils.c utils2.c

BONUS_OBJ		=	$(BONUS_SRC:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= push_swap

BONUS			= checker

all:			$(NAME)

%.o: %.c
				$(CC) -o $@ -c $< $(CFLAGS)

$(NAME):		$(OBJ)
					$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

bonus:			$(BONUS_OBJ)
					$(CC) $(CFLAGS) -o $(BONUS) $(BONUS_OBJ)

clean:
				$(RM) $(OBJ) $(BONUS_OBJ)

fclean:			clean
					$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus

