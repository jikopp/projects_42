# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ferenc <ferenc@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/10 11:08:22 by fnagy             #+#    #+#              #
#    Updated: 2024/10/13 20:20:37 by ferenc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = 	src/ft_printf.c\
		src/ft_print_utils.c\
		src/ft_print_base.c\
		src/ft_print_ptr.c
		
OFILES = $(SRCS:%.c=%.o)

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft/

LIBFT = libft.a


all: $(NAME)

$(NAME): ${LIBFT} $(OFILES)
	ar rcs $(NAME) $(OFILES)

${LIBFT}:
	make bonus -C ${LIBFT_DIR}
	cp ${LIBFT_DIR}${LIBFT} ${NAME}

%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C ${LIBFT_DIR}
	rm -f $(OFILES)

fclean: clean
	make fclean -C ${LIBFT_DIR}
	rm -f $(NAME)
	rm -f ${LIBFT}

re: fclean $(NAME)


.PHONY:	all	clean	fclean	re
