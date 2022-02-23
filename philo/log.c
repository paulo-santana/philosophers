/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 08:06:21 by psergio-          #+#    #+#             */
/*   Updated: 2022/02/23 09:15:29 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	console_log(t_philo *philo, char *message)
{
	long	milis;

	milis = get_elapsed_time(philo->data->started_at);
	printf("%ld %d %s\n", milis, philo->display_id, message);
}