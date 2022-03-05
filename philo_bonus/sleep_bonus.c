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

int	pretend_sleep(t_philo *philo, long amount)
{
	long	current;

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
