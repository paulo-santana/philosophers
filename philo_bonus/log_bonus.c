/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:51:32 by psergio-          #+#    #+#             */
/*   Updated: 2022/03/05 15:33:08 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	console_log(t_philo *philo, char *message)
{
	long	milis;
	sem_t	*lock;

	lock = philo->data->print_lock;
	sem_wait(lock);
	if (check_someone_died(philo->data) == 0)
	{
		milis = get_elapsed_time(philo->data->started_at);
		printf("%ld %d %s\n", milis, philo->display_id, message);
	}
	sem_post(lock);
}
