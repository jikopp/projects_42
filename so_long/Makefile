# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnagy <fnagy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 13:56:48 by fnagy             #+#    #+#              #
#    Updated: 2025/03/06 14:06:56 by fnagy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BIN = bin

SRC  =	src/main.c\
		src/map_open.c\
		src/free_game.c\
		src/open_images.c\
		src/map_print.c\
		src/map_check.c\
		src/map_check2.c\
		src/playable.c\
		src/controllers.c\
		src/door_lock.c\

#OBJ = $(SRC:%.c=%.o)
OBJS	= $(SRC:src/%c=$(BIN)/%o)

LIB_FT = libft/
LIB_FT_A = $(LIB_FT)libft.a

LIB_MLX = minilibx-linux/
LIB_MLX_A = $(LIB_MLX)libmlx.a

INCLUDES = -I/usr/include -Imlx

UNAME := $(shell uname)
RM	= rm -rf

#CC      = cc

CFLAGS = -Wall -Werror -Wextra -O3 -g -I$(LIBM_LX) -I${LIB_FT} -fPIC -fPIE
LFLAGS = -L$(LIB_MLX) -lmlx -L$(LIB_FT) -lft -fPIC -fPIE

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

#$(NAME): ${LIB_FT_A} ${LIB_MLX_A} $(OBJ)
#	$(CC) $(OBJ) $(LFLAGS) -o $(NAME)

$(NAME): $(BIN) $(OBJS) $(LIB_FT_A) $(LIB_MLX_A)
	${CC} $(OBJS) $(LFLAGS) -o $(NAME) 

$(BIN)/%o: src/%c
	${CC} -c $< $(CFLAGS) $(IFLAGS) -o $@
#$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(BIN):
	mkdir -p $(BIN)

$(LIB_FT_A):
	make -C $(LIB_FT)

$(LIB_MLX_A):
	make -C $(LIB_MLX)

#%.o: %.c
#	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	make clean -C $(LIB_FT)
	make clean -C $(LIB_MLX)
	$(RM) $(BIN)

fclean: clean
	make fclean -C $(LIB_FT)
	make clean -C $(LIB_MLX)
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