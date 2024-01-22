# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andreamerlino <andreamerlino@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/21 23:14:45 by andreamerli       #+#    #+#              #
#    Updated: 2024/01/21 23:43:01 by andreamerli      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := pipex

OBJS_BONUS := pipex_bonus.o ft_split_bonus.o get_next_line.o get_next_line_utils.o proccesses_bonus.o utils_pipex_bonus.o fd_opener_bonus.o

OBJS := pipex.o ft_split.o  proccesses.o utils_pipex.o

FT_PRINTF_PATH = ./ft_printf
FT_PRINTF = $(FT_PRINTF_PATH)/libftprintf.a

FLAGS := -Wall -Werror -Wextra

RED = \033[1;31m
LIGHT_BLUE = \033[1;94m
PURPLE = \033[1;35m
ORANGE = \033[0;33m
DEFAULT = \033[0m

all: $(FT_PRINTF) $(NAME)

bonus: $(OBJS_BONUS)
	@gcc $(FLAGS) -o $(NAME) $(OBJS_BONUS)
	@echo "$(LIGHT_BLUE)$(NAME) bonus created!$(DEFAULT)"

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_PATH)

%.o : %.c
	@gcc $(FLAGS) -o $@ -c $<

$(NAME): $(OBJS) $(FT_PRINTF)
	@gcc $(FLAGS) -o $(NAME) $(OBJS) -L$(FT_PRINTF_PATH) -lftprintf
	@echo "$(PURPLE)$(NAME) created!$(DEFAULT)"


clean:
	@rm -f $(OBJS)
	@rm -f $(OBJS_BONUS)
	$(MAKE) -C $(FT_PRINTF_PATH) clean
	@echo "$(RED)object files deleted!$(DEFAULT)"

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(FT_PRINTF_PATH) fclean
	@echo "$(ORANGE) all deleted!$(DEFAULT)"

re: fclean all
