/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:14:22 by psergio-          #+#    #+#             */
/*   Updated: 2022/03/05 15:18:02 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"
#include <sys/time.h>

static void	pickup_forks(t_philo *philo)
{
	sem_wait(philo->data->forks);
	sem_wait(philo->data->forks);
	console_log(philo, "has taken a fork");
	console_log(philo, "has taken a fork");
}

static int	can_eat(t_philo *philo)
{
	int	available_forks;

	if (philo->data->num_philosophers == 1)
		return (0);
	available_forks = *(int *)philo->data->forks;
	if (get_elapsed_time(philo->last_meal) > philo->data->time_to_die / 2
		&& available_forks >= 2)
		return (1);
	if (available_forks >= 2)
		return (1);
	return (0);
}

void	philo_eat(t_philo *philo)
{
	if (get_elapsed_time(philo->last_meal) >= philo->data->time_to_die)
		return (handle_death(philo));
	while (!can_eat(philo))
	{
		if (get_elapsed_time(philo->last_meal) >= philo->data->time_to_die)
			return (handle_death(philo));
		usleep(10);
	}
	pickup_forks(philo);
	console_log(philo, "is eating");
	gettimeofday(&philo->last_meal, NULL);
	if (pretend_sleep(philo, philo->data->time_to_eat) == 0)
		handle_death(philo);
	philo->dinners_had++;
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
}
