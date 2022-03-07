/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:26:11 by psergio-          #+#    #+#             */
/*   Updated: 2022/03/05 15:33:08 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"
#include <semaphore.h>

void	set_someone_died(t_philo *philo)
{
	// printf("philo %d is about to die\n", philo->display_id);
	sem_wait(philo->data->someone_died_lock);
	sem_post(philo->data->someone_died);
	// printf("someone is being killed\n");
	sem_post(philo->data->someone_died_lock);
}

int	check_someone_died(t_philo *philo)
{
	int	someone_died;

	sem_wait(philo->data->someone_died_lock);
	someone_died = *(int *)philo->data->someone_died;
	// printf("someone died: %d\n", someone_died);
	sem_post(philo->data->someone_died_lock);
	return (someone_died);
}

int	get_available_forks(t_philo *philo)
{
	int	available_forks;

	sem_wait(philo->data->forks_lock);
	available_forks = *(int *)philo->data->forks;
	// printf("available forks: %d\n", available_forks);
	sem_post(philo->data->forks_lock);
	return (available_forks);
}

void	take_a_fork(t_philo *philo)
{
	sem_wait(philo->data->forks_lock);
	sem_wait(philo->data->forks);
	sem_post(philo->data->forks_lock);
}

void	return_a_fork(t_philo *philo)
{
	// printf("philo %d is about return a fork\n", philo->display_id);
	sem_wait(philo->data->forks_lock);
	sem_post(philo->data->forks);
	sem_post(philo->data->forks_lock);
}
