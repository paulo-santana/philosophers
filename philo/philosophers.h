/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:11:49 by psergio-          #+#    #+#             */
/*   Updated: 2022/02/23 08:38:09 by psergio-         ###   ########.fr       */
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
	int				num_philosophers;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	max_meals;
	struct timeval	started_at;
};

struct s_philo {
	int		id;
	t_data	*data;
};

void	run_simulation(t_data *data);

int		ft_atoi(const char *str);

long	get_elapsed_time(struct timeval since);

#endif /* !PHILOSOPHERS_H */
