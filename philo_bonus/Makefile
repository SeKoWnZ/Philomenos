NAME = philo_bonus

CFLAGS = -g -Wall -Wextra -Werror -pthread #-fsanitize=thread
IFLAG = -I./include

SRC_DIR = src
OBJ_DIR = obj

FILES = philo_bonus.c table_init_bonus.c checks_bonus.c routine_init_bonus.c \
routines_bonus.c die_protocol_bonus.c philo_utils_bonus.c lib_utils_bonus.c \
error_bonus.c cleanup_bonus.c

OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

DEF_COLOR = $(shell tput sgr0)
RED = $(shell tput setaf 1)
GREEN = $(shell tput setaf 2)

all: $(NAME) ascii_art

$(NAME): $(OBJ_FILES)
	gcc $(CFLAGS) $(IFLAG) -o $@ $^ $(LFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	gcc $(CFLAGS) $(IFLAG) -c $< -o $@

ascii_art:
	@echo "$(GREEN)░▒▓███████▓▒░░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░      ░▒▓██████▓▒░  "
	@echo "░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░ "
	@echo "░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░ "
	@echo "░▒▓███████▓▒░░▒▓████████▓▒░▒▓█▓▒░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░ "
	@echo "░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░ "
	@echo "░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░     ░▒▓█▓▒░░▒▓█▓▒░ "
	@echo "░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒BONUS▒░▒▓████████▓▒░▒▓██████▓▒░  $(DEF_COLOR)"

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
