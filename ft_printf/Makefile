NAME := libftprintf.a

OBJS := ft_printf.o ft_pointer.o ft_putchar.o ft_putdigit.o ft_putstr.o ft_unsint.o ft_putxx.o ft_puthex.o

FLAGS := -Wall -Werror -Wextra



all: $(NAME)

%.o : %.c
	@gcc $(FLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	@ar crs $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
