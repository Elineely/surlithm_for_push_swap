NAME	= push_swap

cc		 = cc
CFALGS	 = -Wall -Wextra -Werror

RM		 = rm -f

INCLUDES = ./push_swap.h	\
		   ./stack_utils.h	\

SRCS	 =  atoi_utils.c	\
			arr4i_utils.c	\
			check_utils.c	\
			stack_orders.c	\
			push_swap.c		\
			sort_stacks.c	\
			sort_stacks_find.c	\
			sort_stacks_get.c	\
			split_utils.c	\
			stack_utils_1.c	\
			stack_utils_2.c	\
			substr_utils.c	\
			sort_big.c		\
			sort_big_utils_1.c \
			sort_big_utils_2.c \
			get_middle.c	\
			sort_reverse.c	\
			sort_reverse_utils.c \
			sort_reverse_find.c \
			sort_small.c	\
			sort_small_utils.c	\
			check_sorted.c	\
			sort_big.c		\
			sort_big_last.c	\


OBJS	= $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re :
	make fclean
	make all

test :
	make all
	make clean

leak :
	make all
	leaks --atExit -- ./push_swap
	make clean

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY : all clean fclean re
