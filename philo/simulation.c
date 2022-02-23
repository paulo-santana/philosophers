/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 08:25:13 by psergio-          #+#    #+#             */
/*   Updated: 2022/02/23 20:13:35 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

t_philo	*new_philosopher(int id, t_data *data)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (philo == NULL)
		return (NULL);
	philo->id = id;
	philo->display_id = id + 1;
	philo->data = data;
	philo->last_meal = data->started_at;
	philo->dinners_had = 0;
	return (philo);
}

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
	t_philo			*philosopher;

	i = 0;
	while (i < data->num_philosophers)
	{
		philosopher = new_philosopher(i, data);
		pthread_create(&ids[i], NULL, philosophize, philosopher);
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
	t_philo		*philo;
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
		pthread_join(philosopher_ids[i], (void **)&philo);
		free(philo);
		i++;
	}
	destroy_forks(data);
	free(philosopher_ids);
}
