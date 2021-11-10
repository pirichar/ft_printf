# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 09:36:57 by pirichar          #+#    #+#              #
#    Updated: 2021/11/10 09:42:52 by pirichar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = libftprintf.a

SRC =  ./utils/ft_putchar_rtn.c		\
	   ./utils/ft_putchar.c			\
	   ./utils/ft_putnbr_rtn_p.c 	\
	   ./utils/ft_putnbro_rtn_neg.c	\
	   ./utils/ft_putnbro_rtn.c		\
	   ./utils/ft_putstring_rtn.c	\
	   ft_printf.c					\



CC = gcc

OBJS = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra 

.c.o : 
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean :
	/bin/rm -f $(OBJS) $(OBJSB)

fclean : clean
	/bin/rm -f $(NAME)
	
re : fclean all

	
