FILES = ft_printf/ft_printf_utils.c ft_printf/ft_printf_utils_2.c \
	ft_printf/ft_printf_utils_3.c ft_printf/ft_printf.c utils.c

FILES_CLIENT = client.c

FILES_SERVER = server.c

FLAGS = -Wall -Werror -Wextra

NAME_SERVER = server

NAME_CLIENT = client

OBJ_CLIENT = $(FILES_CLIENT:.c=.o)

OBJ_SERVER = $(FILES_SERVER:.c=.o)

OBJ = $(FILES:.c=.o)

HEADER = minitalk.h

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER) : $(OBJ_SERVER) $(HEADER) $(OBJ)
	@gcc  $(OBJ_SERVER) $(OBJ) -o $(NAME_SERVER)
	@echo "server is created"

$(NAME_CLIENT) : $(OBJ_CLIENT) $(HEADER)
	@gcc  $(OBJ_CLIENT) $(OBJ) -o $(NAME_CLIENT)
	@echo "client is created"

%.o : %.c $(HEADER)
	@gcc $(FLAGS) -c $< -o $@
	@echo "Compilation $<"

clean:
	@rm -f $(OBJ) $(OBJ_CLIENT) $(OBJ_SERVER)
	@echo "Obj deleted"

fclean: clean
	@rm -f $(NAME_SERVER) $(NAME_CLIENT)
	@echo "All deleted"

re: fclean all

.PHONY : all, clean, fclean, re