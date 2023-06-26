# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nwyseur <nwyseur@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 21:18:35 by nwyseur           #+#    #+#              #
#    Updated: 2023/06/26 10:56:04 by nwyseur          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D

SRCS_FILES	= main.c \

HEADER_FILE	= cub3D_includes.h

SRCS_DIR	= ./srcs/
INC_DIR		= ./includes/

LIBFT		= ./libft/libft.a
LIBFT_PATH	= ./libft

MLX			:= ./minilibx-linux/libmlx.a
MLX_INC		:= ./minilibx-linux
MLX_LIB		:= -lX11 -lXext -L./minilibx-linux -lmlx

SRCS		= $(addprefix ${SRCS_DIR}, ${SRCS_FILES})
OBJS		= ${SRCS:.c=.o}
HEADER		= $(addprefix ${INC_DIR}, ${HEADER_FILE})

CC			= cc
CC_FLAGS	= -Wall -Wextra -Werror -g

RM			= rm -f

%.o : %.c	${HEADER}
			${CC} ${CC_FLAGS} -I${INC_DIR} -I${MLX_INC} -c $< -o $@

all:		${NAME}

${NAME}:	${OBJS} ${LIBFT} ${MLX}
			${CC} ${CC_FLAGS} -I${INC_DIR} -I${MLX_INC} -o ${NAME} ${OBJS} ${LIBFT} -lft ${MLX_LIB}
			@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

${LIBFT}:	
			make -C ${LIBFT_PATH}

${MLX}:
			make -C ${MLX_INC}

clean:
			make -C ${LIBFT_PATH} clean
			make -C ${MLX_INC} clean
			${RM} ${OBJS} ${BONUS_OBJS}
			@echo "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:		clean
			make -C ${LIBFT_PATH} fclean
			${RM} ${NAME} ${NAME_BONUS}
			@echo "$(RED)all deleted!$(DEFAULT)"

re:			fclean all

.PHONY: 	all clean fclean re bonus

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
