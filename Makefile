# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbaron <vbaron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/24 11:51:53 by vbaron            #+#    #+#              #
#    Updated: 2021/12/08 18:05:40 by vbaron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIR_S = srcs
DIR_O = objs

SOURCES = 	main.c \
			error.c \
			utils.c \
			check_args.c \
			fill_mother.c \
			print_mother_attrs.c \
			dinner_time.c \
			sit_down_philos.c \
			check_if_dead.c \
			lock_unlock_forks.c \
			print_philos.c \

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))
OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))
HEADERS = headers

NAME = philo

CC = clang

CFLAGS = -Wall -Wextra -Werror -g -pthread #-fsanitize=address

all: $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	mkdir -p $(DIR_O)	
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $^ -o $@

clean:
		rm -f $(OBJS)		
	rm -f $(OBJS)/*.o
	rm -rf $(DIR_O)	

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re fclean all clean