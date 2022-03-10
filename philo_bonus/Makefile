NAME = philo_bonus

SRC = main_bonus.c					\
	  simulation_bonus.c			\
	  ft_atoi_bonus.c				\
	  number_validation_bonus.c		\
	  philo_eat_bonus.c				\
	  time_bonus.c					\
	  log_bonus.c					\
	  death_bonus.c					\
	  sleep_bonus.c					\
	  steps_bonus.c					\
	  lock_bonus.c					\

OBJ_DIR = ./obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: all
	./$(NAME) 5 800 200 200 7

$(OBJ_DIR):
	mkdir -p ./obj

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
