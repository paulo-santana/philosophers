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

void	set_someone_died(t_data *data)
{
	sem_wait(data->someone_died_lock);
	sem_post(data->someone_died);
	sem_post(data->someone_died_lock);
}

int	check_someone_died(t_data *data)
{
	int	someone_died;

	sem_wait(data->someone_died_lock);
	someone_died = *(int *)data->someone_died;
	sem_post(data->someone_died_lock);
	return (someone_died);
}
