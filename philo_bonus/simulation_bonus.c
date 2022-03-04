/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psergio- <psergio->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:23:31 by psergio-          #+#    #+#             */
/*   Updated: 2022/03/04 17:38:56 by psergio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"
#include <sys/types.h>
#include <errno.h>
#include <sys/wait.h>
#include <stdio.h>

void	philosophize(int index, t_data *data)
{
	(void)data;
	printf("philosopher %d is philosophizing\n", index);
	exit(0);
}

void	collect_childs(pid_t *pids, t_data *data)
{
	int	i;
	int	wstatus;

	i = 0;
	while (i < data->num_philosophers)
	{
		waitpid(pids[i], &wstatus, 0);
		i++;
	}
}

void	run_simulation(t_data *data)
{
	int		i;
	pid_t	pid;
	pid_t	*pids;

	pids = malloc(sizeof(pid_t) * data->num_philosophers);
	if (pids == NULL)
		exit(ENOMEM);
	i = 0;
	while (i < data->num_philosophers)
	{
		pid = fork();
		if (pid == 0)
			philosophize(i, data);
		else
			pids[i] = pid;
		i++;
	}
	collect_childs(pids, data);
}
