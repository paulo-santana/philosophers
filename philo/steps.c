/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 08:46:14 by psergio-          #+#    #+#             */
/*   Updated: 2022/02/23 09:24:50 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>
#include <unistd.h>

void	identify_forks(t_philo *philo, t_fork **right, t_fork **left)
{
	*right = &philo->data->forks[philo->id];
	if (philo->display_id == philo->data->num_philosophers)
		*left = &philo->data->forks[0];
	else
		*left = &philo->data->forks[philo->id + 1];
}

void	pickup_forks(t_philo *philo, t_fork *right, t_fork *left)
{
	t_fork	*first;
	t_fork	*second;

	if (philo->id % 2 == 0)
	{
		first = right;
		second = left;
	}
	else
	{
		first = left;
		second = right;
	}
	pthread_mutex_lock(&first->mutex);
	console_log(philo, "has taken a fork");
	pthread_mutex_lock(&second->mutex);
	console_log(philo, "has taken a fork");
}

void	philo_eat(t_philo *philo)
{
	t_fork	*right;
	t_fork	*left;

	identify_forks(philo, &right, &left);
	pickup_forks(philo, right, left);
	console_log(philo, "is eating");
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(&right->mutex);
	pthread_mutex_unlock(&left->mutex);
}

void	philo_sleep(t_philo *philo)
{
	console_log(philo, "is sleeping");
	usleep(philo->data->time_to_sleep * 1000);
}
