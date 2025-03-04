# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ferenc <ferenc@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 13:56:48 by fnagy             #+#    #+#              #
#    Updated: 2025/02/12 15:43:32 by ferenc           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
BIN = bin

SRC  =	src/pipex.c\
		src/utilities.c\
		src/utilities2.c\

OBJS	= $(SRC:src/%c=$(BIN)/%o)

LIB_FT = libft/
LIB_FT_A = $(LIB_FT)libft.a

INCLUDES = -I/usr/include

UNAME := $(shell uname)
RM	= rm -rf

CFLAGS = -Wall -Werror -Wextra -O3 -g -I${LIB_FT}
LFLAGS = -L$(LIB_FT) -lft

ifeq ($(UNAME), Darwin) # iMac / iOS
	CC = gcc
	LFLAGS += -framework OpenGL -framework AppKit
else ifeq ($(UNAME), FreeBSD) # FreeBSD./
	CC = clang
else #Linux and others...
	CC = cc
	LFLAGS += -lbsd -lXext -lX11 -lm
endif


all: $(NAME)

$(NAME): $(BIN) $(OBJS) $(LIB_FT_A)
	${CC} $(OBJS) $(LFLAGS) -o $(NAME) 

$(BIN)/%o: src/%c
	${CC} -c $< $(CFLAGS) $(IFLAGS) -o $@

$(BIN):
	mkdir -p $(BIN)

$(LIB_FT_A):
	make -C $(LIB_FT)

clean:
	make clean -C $(LIB_FT)
	$(RM) $(BIN)

fclean: clean
	make fclean -C $(LIB_FT)
	$(RM) $(NAME)

re: fclean $(NAME)

show:
	@printf "UNAME		: $(UNAME)\n"
	@printf "NAME  		: $(NAME)\n"
	@printf "CC		: $(CC)\n"
	@printf "CFLAGS		: $(CFLAGS)\n"
	@printf "LFLAGS		: $(LFLAGS)\n"
	@printf "SRC		: $(SRC)\n"
	@printf "OBJ		: $(OBJ)\n"

.PHONY: all clean fclean re show