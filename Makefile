NAME	=	push_swap

CC		=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM		=	rm -f


FILES = push_swap.c \
		utils.c \
		swap.c \
		t_lists.c \
		push.c \
		reverse_rotate.c \
		rotate.c 

LIBFT = libft/libft.a

		  
FtoO	= $(FILES:.c=.o)

all:        $(NAME)

$(NAME):   $(LIBFT) ${FtoO}
	$(CC) $(CFLAGS) $(FtoO) $(LIBFT) -o $(NAME) 

$(LIBFT):
	make -C ./libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C libft
	$(RM) $(FtoO)

fclean: clean
	make fclean -C libft
	$(RM) $(NAME) $(FtoO)

re: fclean $(NAME)

.PHONY: all clean fclean re