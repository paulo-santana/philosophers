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

void	handle_death(t_philo *philo)
{
	sem_wait(philo->data->print_death_lock);
	console_log(philo, "died");
	set_someone_died(philo);
	sem_post(philo->data->print_death_lock);
}
