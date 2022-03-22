/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 08:46:14 by psergio-          #+#    #+#             */
/*   Updated: 2022/02/23 20:37:04 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>

void	philo_sleep(t_philo *philo)
{
	console_log(philo, "is sleeping");
	if (pretend_sleep(philo, philo->data->time_to_sleep) == 0)
		handle_death(philo);
}

void	philo_think(t_philo *philo)
{
	long	safe_time_to_think;

	console_log(philo, "is thinking");
	safe_time_to_think = philo->data->time_to_die - philo->data->time_to_eat
		- philo->data->time_to_sleep;
	safe_time_to_think /= 2;
	if (safe_time_to_think < 0)
		return ;
	pretend_sleep(philo, safe_time_to_think);
}
