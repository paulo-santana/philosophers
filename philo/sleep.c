/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:22:00 by psergio-          #+#    #+#             */
/*   Updated: 2022/02/23 20:43:15 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <bits/types/struct_timeval.h>
#include <sys/time.h>
#include <unistd.h>

int	pretend_sleep(t_philo *philo, long amount)
{
	long			current;
	long			last_meal;
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
