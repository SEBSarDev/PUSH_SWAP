CC = clang
FLAGS = -Wall -Werror -Wextra
NAME = push_swap
SRCS = srcs/run/main.c \
       srcs/run/apply_instruction.c \
       srcs/run/operation.c \
       srcs/run/radix.c \
       srcs/run/short_sort.c \
       srcs/run/print.c \
       srcs/run/fill_pile.c \
       srcs/run/indexage.c \
       srcs/utils/utils.c \
       srcs/utils/utils_lst.c \
       srcs/utils/utils_lst_print.c \
       srcs/utils/ft_atoi.c \
       srcs/utils/ft_itoa.c \
       srcs/utils/convert_base.c \
       srcs/utils/ft_split.c \
       srcs/utils/check_format.c \
       srcs/utils/error.c

OBJS = $(SRCS:.c=.o)
$(NAME) : $(OBJS)
	$(CC) $(OBJS) -I./includes $(FLAGS) -o $(NAME)
all : $(NAME)
clean : 
	rm -rf $(OBJS)
fclean : clean
	rm -rf $(NAME)
re : fclean all
.PHONY: all clean fclean re
