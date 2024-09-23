# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mayyildi <mayyildi@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/21 10:41:14 by mayyildi          #+#    #+#              #
#    Updated: 2022/07/09 22:00:34 by mayyildi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

SRCS	=	pipex.c					\
			get_paths.c				\
			minilib/ft_strlen.c		\
			minilib/ft_strlcpy.c	\
			minilib/ft_substr.c		\
			minilib/ft_strdup.c		\
			minilib/ft_split.c		\
			minilib/ft_bzero.c		\
			minilib/ft_calloc.c		\
			minilib/ft_memset.c		\
			minilib/ft_strjoin.c	\
			minilib/ft_strnstr.c	\

OBJS	= ${SRCS:.c=.o}

CC		=	gcc

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror

all:		${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}
clean:
	${RM} ${OBJS}

fclean:		clean
	${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
