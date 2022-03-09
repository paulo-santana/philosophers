/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:23:31 by psergio-          #+#    #+#             */
/*   Updated: 2022/03/05 15:33:08 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"
#include <semaphore.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

t_philo	*new_philosopher(int index, t_data *data)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (philo == NULL)
		exit(2);
	philo->id = index;
	philo->display_id = index + 1;
	philo->last_meal = data->started_at;
	philo->dinners_had = 0;
	philo->data = data;
	return (philo);
}

static void	clear_semaphores(t_data *data)
{
	sem_close(data->someone_died_lock);
	sem_close(data->someone_died);
	sem_close(data->print_death_lock);
	sem_close(data->print_lock);
	sem_close(data->forks);
	sem_close(data->forks_lock);
	sem_unlink("/someone_died_lock");
	sem_unlink("/someone_died");
	sem_unlink("/print_death");
	sem_unlink("/print_lock");
	sem_unlink("/forks");
	sem_unlink("/forks_lock");
}

void	philosophize(int index, t_data *data)
{
	t_philo	*philo;

	philo = new_philosopher(index, data);
	if (philo->id % 2 == 0)
		usleep(500);
	while (check_someone_died(philo) == 0)
	{
		philo_eat(philo);
		if (philo->dinners_had >= philo->data->max_meals)
			break ;
		philo_sleep(philo);
		philo_think(philo);
	}
	free(philo);
	clear_semaphores(data);
	free(data->pids);
	exit(0);
}

void	collect_childs(t_data *data)
{
	int	i;
	int	wstatus;

	i = 0;
	while (i < data->num_philosophers)
	{
		waitpid(data->pids[i], &wstatus, 0);
		i++;
	}
	free(data->pids);
}

void	run_simulation(t_data *data)
{
	int		i;
	pid_t	pid;

	data->pids = malloc(sizeof(pid_t) * data->num_philosophers);
	if (data->pids == NULL)
		exit(ENOMEM);
	i = 0;
	while (i < data->num_philosophers)
	{
		pid = fork();
		if (pid == 0)
			philosophize(i, data);
		else
			data->pids[i] = pid;
		i++;
	}
	collect_childs(data);
}
