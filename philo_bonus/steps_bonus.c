/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:12:50 by psergio-          #+#    #+#             */
/*   Updated: 2022/03/05 15:13:49 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

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
