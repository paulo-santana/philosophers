/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 08:25:13 by psergio-          #+#    #+#             */
/*   Updated: 2022/02/23 20:42:52 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	*philosophize(void *data)
{
	t_philo	*philo;

	philo = data;
	while (!check_someone_died(philo->data))
	{
		philo_eat(data);
		if (philo->dinners_had >= philo->data->max_meals)
			break ;
		philo_sleep(data);
		philo_think(data);
	}
	return (data);
}

void	init_philosophers(pthread_t *ids, t_data *data)
{
	int				i;
	t_philo			*philosophers;
	t_philo			*philo;

	i = 0;
	philosophers = malloc(sizeof(t_philo) * data->num_philosophers);
	memset(philosophers, 0, sizeof(t_philo) * data->num_philosophers);
	data->phillosophers = philosophers;
	while (i < data->num_philosophers)
	{
		philo = &philosophers[i];
		philo->id = i;
		philo->display_id = i + 1;
		philo->data = data;
		philo->last_meal = data->started_at;
		philo->dinners_had = 0;
		pthread_create(&ids[i], NULL, philosophize, philo);
		i++;
	}
}

void	init_forks(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(t_fork) * data->num_philosophers);
	if (data->forks == NULL)
		return ;
	i = 0;
	while (i < data->num_philosophers)
	{
		pthread_mutex_init(&data->forks[i].mutex, NULL);
		pthread_mutex_init(&data->forks[i].is_locked_mutex, NULL);
		data->forks[i].is_locked = 0;
		i++;
	}
}

void	destroy_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philosophers)
	{
		pthread_mutex_destroy(&data->forks[i].mutex);
		pthread_mutex_destroy(&data->forks[i].is_locked_mutex);
		i++;
	}
	free(data->forks);
}

void	run_simulation(t_data *data)
{
	pthread_t	*philosopher_ids;
	int			i;

	philosopher_ids = malloc(sizeof(pthread_t) * data->num_philosophers);
	if (philosopher_ids == NULL)
		return ;
	init_forks(data);
	init_philosophers(philosopher_ids, data);
	i = 0;
	while (i < data->num_philosophers)
	{
		pthread_join(philosopher_ids[i], NULL);
		i++;
	}
	destroy_forks(data);
	free(philosopher_ids);
	free(data->phillosophers);
}
