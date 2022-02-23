#include "philosophers.h"

int	validate_args(int argc, char **argv)
{
	(void)argv;
	return (argc);
}

int main(int argc, char **argv)
{
	t_data	data;

	if (validate_args(argc, argv) == 0)
		return (1);
	gettimeofday(&data.started_at, NULL);
	data.num_philosophers = ft_atoi(argv[1]);
	data.time_to_die = ft_atoi(argv[2]);
	data.time_to_eat = ft_atoi(argv[3]);
	data.time_to_sleep = ft_atoi(argv[4]);
	data.no_one_died = 1;
	data.max_meals = -1;
	if (argc == 6)
		data.max_meals = ft_atoi(argv[5]);
	pthread_mutex_init(&data.print_lock, NULL);
	pthread_mutex_init(&data.no_one_died_mutex, NULL);
	run_simulation(&data);
	pthread_mutex_destroy(&data.print_lock);
	pthread_mutex_destroy(&data.no_one_died_mutex);
}
