/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:59:08 by psergio-          #+#    #+#             */
/*   Updated: 2022/03/04 17:27:00 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <semaphore.h>
# include <sys/time.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_data	t_data;
typedef struct s_philo	t_philo;

struct s_data {
	int				num_philosophers;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	max_meals;
	struct timeval	started_at;
	sem_t			**forks;
	sem_t			*no_one_died;
	sem_t			*print_lock;
	sem_t			*print_death_lock;
};

struct s_philo {
	int				id;
	int				display_id;
	unsigned int	dinners_had;
	struct timeval	last_meal;
	t_data			*data;
};

int		ft_atoi(const char *str);
void	run_simulation(t_data *data);

#endif
