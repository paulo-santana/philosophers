/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:59:08 by psergio-          #+#    #+#             */
/*   Updated: 2022/03/05 15:33:08 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

# include <semaphore.h>
# include <sys/time.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_data	t_data;
typedef struct s_philo	t_philo;

struct s_data {
	int				num_philosophers;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	unsigned long	max_meals;
	struct timeval	started_at;
	pid_t			*pids;
	sem_t			*forks;
	sem_t			*forks_lock;
	sem_t			*someone_died;
	sem_t			*someone_died_lock;
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

int				is_int(char *number);
int				ft_atoi(const char *str);
void			run_simulation(t_data *data);
void			clear_semaphores(t_data *data);

void			philo_eat(t_philo *philo);
void			philo_sleep(t_philo *philo);
void			philo_think(t_philo *philo);

void			set_someone_died(t_philo *philo);
int				check_someone_died(t_philo *philo);
int				get_available_forks(t_philo *philo);
void			take_a_fork(t_philo *philo);
void			return_a_fork(t_philo *philo);

void			console_log(t_philo *philo, char *message);
unsigned long	get_elapsed_time(struct timeval since);
int				pretend_sleep(t_philo *philo, unsigned long amount);
void			handle_death(t_philo *philo);

#endif
