SERVER	=	server
CLIENT	=	client

LIBFT_PATH	=	libft

CC		=	gcc
CFLAGS	=	#-Wall -Werror -Wextra
RM 		= 	rm -rf

all		: 	server client

bonus	:	server client

server	:	lib
			$(CC) $(CFLAGS)  $(SERVER:=.c) -o $(SERVER) -L$(LIBFT_PATH) -lft

client	: 	lib
			$(CC) $(CFLAGS)  $(CLIENT:=.c) -o $(SERVER) -L$(LIBFT_PATH) -lft

lib	:
			make -C $(LIBFT_PATH)

clean	:	
			$(RM) -rf $(SERVER:.c=.o) $(CLIENT:.c=.o)
			# make clean -C $(LIBFT_PATH)

fclean	:	clean
			$(RM) $(SERVER) $(CLIENT)
			# make fclean -C $(LIBFT_PATH)

re		:	fclean all

.phony	:	all clean fclean re