/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 09:55:16 by psergio-          #+#    #+#             */
/*   Updated: 2022/02/23 10:02:15 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>

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

int	can_eat(t_philo *philo, t_fork *right_fork, t_fork *left_fork)
{
	if (right_fork == left_fork)
		return (0);
	if (get_elapsed_time(philo->last_meal) > philo->data->time_to_die / 2)
		return (1);
	if (right_fork->is_locked || left_fork->is_locked)
		return (0);
	return (1);
}

void	handle_death(t_philo *philo)
{
	console_log(philo, "died");
	philo->data->no_one_died = 0;
}

void	philo_eat(t_philo *philo)
{
	t_fork	*right;
	t_fork	*left;

	if (!philo->data->no_one_died)
		return ;
	identify_forks(philo, &right, &left);
	while (!can_eat(philo, right, left))
	{
		if (get_elapsed_time(philo->last_meal) >= philo->data->time_to_die)
			return (handle_death(philo));
		usleep(1000);
	}
	pickup_forks(philo, right, left);
	console_log(philo, "is eating");
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_unlock(&right->mutex);
	pthread_mutex_unlock(&left->mutex);
}
