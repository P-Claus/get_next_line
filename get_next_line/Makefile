# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pclaus <pclaus@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/22 20:47:13 by pclaus            #+#    #+#              #
#    Updated: 2023/11/22 20:49:20 by pclaus           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = getnextline.a

CFLAGS = -Wall -Werror -Wextra

CC = cc

RM = rm -f

SOURCES = get_next_line.c get_next_line_utils.c

OBJ_FILES = $(SOURCES:%.c=%.o)

#colours
GREEN = \033[0;92m

$(NAME): $(SOURCES)
	cc $(CFLAGS) -c $(SOURCES)
	@ar rcs $(NAME) $(OBJ_FILES)
	@echo "$(GREEN)getnextline.a has been compiled!"

clean:
	@$(RM) $(OBJ_FILES)
	@echo "$(GREEN)The object files have been removed!"

fclean: 
	@$(RM) $(OBJ_FILES)
	@$(RM) $(NAME)
	@echo "$(GREEN)The object files and library have been removed!"

re:	fclean $(NAME)

.PHONY:			all clean fclean re bonus
