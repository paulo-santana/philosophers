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
	struct timeval	started_sleeping;
	long			current;

	gettimeofday(&started_sleeping, NULL);
	current = 0;
	while (current < amount)
	{
		usleep(100);
		current = get_elapsed_time(philo->last_meal);
		if (current >= philo->data->time_to_die)
			return (0);
	}
	return (1);
}
