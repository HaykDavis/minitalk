NAME		= server
NAME_C		= client
NAME_B		= server_bonus
NAME_CB		= client_bonus

SRCS		= main_server.c
SRCS_B		= main_server_bonus.c
SRCS_C		= main_client.c
SRCS_CB		= main_client_bonus.c
SRCS_S		= utils.c

HEADER		= utils.h

CC = gcc

RM = rm -f

FLAGS = -Wall -Wextra -Werror

all: $(NAME) $(NAME_C) 

$(NAME) : $(SRCS) $(SRCS_S)
	@$(CC) $(SRCS) $(SRCS_S) -o $(NAME)
	@printf "server was build ✅\n"

$(NAME_C) : $(SRCS_C) $(SRCS_S)
	@$(CC) $(SRCS_C) $(SRCS_S) -o $(NAME_C)
	@printf "client was build ✅\n"

bonus:	$(NAME_B) $(NAME_CB)

$(NAME_B) : $(SRCS_B) $(SRCS_S)
	@$(CC) $(SRCS_B) $(SRCS_S) -o $(NAME_B)
	@printf "server_bonus was build ✅\n"

$(NAME_CB) : $(SRCS_CB) $(SRCS_S)
	@$(CC) $(SRCS_CB) $(SRCS_S) -o $(NAME_CB)
	@printf "client_bonus was build ✅\n"

%.o: %.c	$(HEADER)
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

clean:
		@$(RM) $(NAME) $(NAME_C) $(NAME_B) $(NAME_CB)
		@printf "Everything is in trash 🗑\n"

fclean: clean

re: fclean all

rebonus: fclean bonus

.PHONY : all clean fclean re bonus rebonus