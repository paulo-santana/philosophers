NAME = philo

SRC = main.c						\
	  simulation.c					\
	  steps.c						\
	  steps_eating.c				\
	  ft_atoi.c						\
	  number_validation.c			\
	  lock.c						\
	  log.c							\
	  time.c						\
	  sleep.c						\

OBJ_DIR = ./obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -pthread

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

$(OBJ_DIR):
	mkdir -p ./obj

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
