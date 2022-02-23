NAME = philo/philo

vpath %.c philo						\

SRC = main.c						\
	  simulation.c					\
	  steps.c						\
	  steps_eating.c				\
	  ft_atoi.c						\
	  log.c							\
	  time.c						\
	  # init.c						\

OBJ_DIR = ./obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3 #-fsanitize=thread
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	mkdir -p philo
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME) 100 400 100 100 7

$(OBJ_DIR):
	mkdir -p ./obj

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
