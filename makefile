MINISHELL = minishell
# readlineのpathを指定してね
RPATH :=  -L/opt/homebrew/opt/readline/lib -lreadline

FLAGS := -Wall -Werror -Wextra
HEADERS := -I./includes/
LIBS := $(RPATH) -L$(PWD)/libft
CFLAGS := $(FLAGS) $(HEADERS)

SRC_LIST := minishell.c

SRC_PATH := ./
FILES := $(addprefix $(SRC_PATH), $(SRC_LIST))

all: $(MINISHELL)

$(MINISHELL):
	@make -C ./libft
	@gcc $(CFLAGS) $(FILES) $(LIBS) ./libft/libft.a  -o $(MINISHELL)
	@printf "\033[31mS\033[0m"
	@printf "\033[33mU\033[0m"
	@printf "\033[32mC\033[0m"
	@printf "\033[36mC\033[0m"
	@printf "\033[34mE\033[0m"
	@printf "\033[35mS\033[0m"
	@printf "\033[31mS\033[0m"
	@printf "\033[33m!\033[0m"
	@printf "\033[32m!\033[0m"
	@echo "\n"

clean:
	make -C ./libft clean

fclean: clean
	rm -f $(MINISHELL)
	make -C ./libft fclean

re: fclean all

run: re
	@./minishell
