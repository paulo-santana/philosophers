/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:11:49 by psergio-          #+#    #+#             */
/*   Updated: 2022/02/23 08:15:41 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>

typedef struct s_data	t_data;
typedef struct s_philo	t_philo;

struct s_data {
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	long			started_at;
};

struct s_philo {
	int		id;
	t_data	*data;
};

int		ft_atoi(const char *str);

long	get_elapsed_time(struct timeval since);

#endif /* !PHILOSOPHERS_H */
