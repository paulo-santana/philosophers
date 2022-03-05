/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:58:43 by psergio-          #+#    #+#             */
/*   Updated: 2022/03/05 15:33:08 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"
#include <semaphore.h>
#include <sys/stat.h>
#include <stdio.h>

int	validate_args(int argc, char **argv)
{
	(void)argv;
	if (argc == 5 || argc == 6)
		return (1);
	return (0);
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
	data->someone_died_lock
		= sem_open("/someone_died_lock", O_CREAT, S_IRUSR | S_IWUSR, 1);
	data->someone_died
		= sem_open("/someone_died", O_CREAT, S_IRUSR | S_IWUSR, 0);
	data->print_death_lock
		= sem_open("/print_death", O_CREAT, S_IRUSR | S_IWUSR, 1);
	data->print_lock
		= sem_open("/print_lock", O_CREAT, S_IRUSR | S_IWUSR, 1);
	data->forks
		= sem_open("/forks", O_CREAT, S_IWUSR | S_IRUSR, num_philosophers);
}

static void	clear_semaphores(t_data *data)
{
	sem_close(data->someone_died_lock);
	sem_close(data->print_death_lock);
	sem_close(data->print_lock);
	sem_close(data->forks);
	sem_unlink("/someone_died_lock");
	sem_unlink("/print_death");
	sem_unlink("/print_lock");
	sem_unlink("/forks");
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
