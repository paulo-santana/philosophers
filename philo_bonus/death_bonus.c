/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 14:46:22 by psergio-          #+#    #+#             */
/*   Updated: 2022/03/05 15:33:08 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"
#include <semaphore.h>

void	handle_death(t_philo *philo)
{
	long	milis;

	sem_wait(philo->data->print_lock);
	sem_wait(philo->data->print_death_lock);
	if (check_someone_died(philo) == 0)
	{
		milis = get_elapsed_time(philo->data->started_at);
		printf("%ld %d %s\n", milis, philo->display_id, "died");
	}
	set_someone_died(philo);
	sem_post(philo->data->print_death_lock);
	sem_post(philo->data->print_lock);
}
