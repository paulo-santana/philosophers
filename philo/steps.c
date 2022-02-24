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
	console_log(philo, "is thinking");
	usleep(500);
}
