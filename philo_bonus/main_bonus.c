/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:58:43 by psergio-          #+#    #+#             */
/*   Updated: 2022/03/04 19:00:14 by psergio-         ###   ########.fr       */
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
	data.no_one_died = sem_open("/no_one_died", O_CREAT, S_IRUSR | S_IWUSR, 1);
	data.forks = sem_open("/forks", O_CREAT, S_IWUSR | S_IRUSR,
			data.num_philosophers);
	if (argc == 6)
		data.max_meals = ft_atoi(argv[5]);
	run_simulation(&data);
	sem_close(data.no_one_died);
	sem_unlink("/no_one_died");
	sem_unlink("/forks");
}
