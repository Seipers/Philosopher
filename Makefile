##
## Makefile for philo in /home/sebastien/Rendu/philo
## 
## Made by Sebastien Le Guischer
## Login   <sebastien@epitech.net>
## 
## Started on  Sun Mar 12 07:06:10 2017 Sebastien Le Guischer
## Last update Wed Mar 15 16:31:08 2017 Sebastien Le Guischer
##

NAME		= philo

SRCS		= main.c\
		  list.c\
		  action.c\
		  decide.c

OBJS		= $(SRCS:.c=.o)

CFLAGS		= -W -Wall -Wextra -Iinclude -pthread -lriceferee -L./

GCC		= gcc

RM		= rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
	$(GCC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
