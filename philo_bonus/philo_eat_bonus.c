/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:14:22 by psergio-          #+#    #+#             */
/*   Updated: 2022/03/04 18:20:55 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"
#include <semaphore.h>

void	philo_eat(t_philo *philo)
{
	if (*(long *)philo->data->no_one_died > 0)
		sem_wait(philo->data->no_one_died);
}
