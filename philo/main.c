/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 21:24:33 by psergio-          #+#    #+#             */
/*   Updated: 2022/03/09 21:53:18 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	data.no_one_died = 1;
	data.max_meals = -1;
	if (argc == 6)
		data.max_meals = ft_atoi(argv[5]);
	pthread_mutex_init(&data.print_lock, NULL);
	pthread_mutex_init(&data.no_one_died_mutex, NULL);
	pthread_mutex_init(&data.print_death_lock, NULL);
	run_simulation(&data);
	pthread_mutex_destroy(&data.print_lock);
	pthread_mutex_destroy(&data.no_one_died_mutex);
	pthread_mutex_destroy(&data.print_death_lock);
}
