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

void	philo_eat(t_philo *philo)
{
	sem_wait(philo->data->forks);
	console_log(philo, "has taken a fork");
	sem_wait(philo->data->forks);
	console_log(philo, "has taken a fork");
	console_log(philo, "is eating");
	gettimeofday(&philo->last_meal, NULL);
	if (pretend_sleep(philo, philo->data->time_to_eat) == 0)
		handle_death(philo);
	philo->dinners_had++;
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
}
