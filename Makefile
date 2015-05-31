# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alakatos <lakatosandrei@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/17 15:39:07 by alakatos          #+#    #+#              #
#    Updated: 2015/05/31 15:51:31 by alakatos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = colectie

SRCS = program.cpp

OBJS = $(SRCS:.cpp=.o)

CC = g++

FLAGS = -Wall -Wextra -Werror

CFLAG = -c

NFLAG = -o

DFLAG = -g

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(CFLAG) $(DFLAG) $(SRCS)
	$(CC) $(FLAGS) $(NFLAG) $(NAME) $(OBJS) $(DFLAG)

RM = rm

RMT = -rf

clean:
	$(RM) $(RMT) $(OBJS)

fclean: clean
	$(RM) $(RMT) $(NAME) $(NAME).dsYM

re: fclean all
