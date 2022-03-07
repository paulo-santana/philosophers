/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:41:03 by psergio-          #+#    #+#             */
/*   Updated: 2022/03/05 14:44:19 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"
#include <stdio.h>

int	pretend_sleep(t_philo *philo, unsigned long amount)
{
	unsigned long	current;
	unsigned long	last_meal;
	struct timeval	started_sleep;

	current = 0;
	gettimeofday(&started_sleep, NULL);
	while (current < amount)
	{
		usleep(100);
		last_meal = get_elapsed_time(philo->last_meal);
		if (last_meal >= philo->data->time_to_die)
			return (0);
		current = get_elapsed_time(started_sleep);
	}
	return (1);
}
