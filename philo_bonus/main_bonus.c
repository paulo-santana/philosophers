/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:58:43 by psergio-          #+#    #+#             */
/*   Updated: 2022/03/09 22:09:17 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"
#include <semaphore.h>
#include <sys/stat.h>
#include <stdio.h>

int	print_help(char *program_name)
{
	printf("Usage: %s time_to_die time_to_eat time_to_sleep [max_meals]\n\n",
		program_name);
	printf("Where:\n"
		"\ttime_to_die: the time it takes for a philosopher"
		" to die after his last meal\n"
		"\ttime_to_eat: the time it takes for a philosopher to eat\n"
		"\ttime_to_sleep: the time it takes for a philosopher to sleep\n"
		"\tmax_meals (optional): the simulation will stop after each"
		" philosopher eat this many times\n\n"
		"All the times are in milliseconds.\n"
		"All arguments must be positive integers\n"
		);
	return (0);
}

int	validate_args(int argc, char **argv)
{
	int	i;

	if (argc != 5 && argc != 6)
		return (print_help(argv[0]));
	i = 1;
	while (i < argc)
	{
		if (!is_int(argv[i]))
			return (print_help(argv[0]));
		if (ft_atoi(argv[i]) < 0)
			return (print_help(argv[0]));
		i++;
	}
	return (argc);
}

static sem_t	*new_semaphore(char *name, int initial_value)
{
	return (sem_open(name, O_CREAT, S_IRUSR | S_IWUSR, initial_value));
}

static void	init_semaphores(t_data *data)
{
	int	num_philosophers;

	num_philosophers = data->num_philosophers;
	sem_unlink("/someone_died_lock");
	sem_unlink("/someone_died");
	sem_unlink("/print_death");
	sem_unlink("/print_lock");
	sem_unlink("/forks");
	sem_unlink("/forks_lock");
	data->someone_died_lock = new_semaphore("/someone_died_lock", 1);
	data->someone_died = new_semaphore("/someone_died", 0);
	data->print_death_lock = new_semaphore("/print_death", 1);
	data->print_lock = new_semaphore("/print_lock", 1);
	data->forks = new_semaphore("/forks", num_philosophers);
	data->forks_lock = new_semaphore("/forks_lock", 1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (validate_args(argc, argv) == 0)
		return (1);
	gettimeofday(&data.started_at, NULL);
	data.num_philosophers = ft_atoi(argv[1]);
	data.time_to_die = ft_atoi(argv[2]);
	data.time_to_eat = ft_atoi(argv[3]);
	data.time_to_sleep = ft_atoi(argv[4]);
	data.max_meals = -1;
	if (argc == 6)
		data.max_meals = ft_atoi(argv[5]);
	init_semaphores(&data);
	run_simulation(&data);
	clear_semaphores(&data);
}
