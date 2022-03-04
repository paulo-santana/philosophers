NAME = philosophers
MANDATORY = philo/philo
BONUS = philo_bonus/philo_bonus

RM = rm -rf

all: $(NAME)

$(NAME): $(MANDATORY) $(BONUS)

$(MANDATORY):
	make -C philo

$(BONUS):
	make -C philo_bonus

clean:
	make -C philo clean
	make -C philo_bonus clean

fclean: clean
	make -C philo fclean
	make -C philo_bonus fclean

re: fclean all

run: $(BONUS)
	$(BONUS) 4 210 100 100 7
