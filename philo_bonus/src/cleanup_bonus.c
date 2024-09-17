/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 00:20:30 by jose-gon          #+#    #+#             */
/*   Updated: 2024/09/17 22:52:17 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

void	cleanup(t_table *table)
{
	t_table	*tmp;
	int		i;

	i = -1;
	tmp = table;
	sem_close(tmp->sem_forks);
	sem_close(tmp->sem_print);
	while (++i < tmp->philo_n)
		free(tmp->philo[i]);
	free(tmp->philo);
	free(tmp);
}

void	wait_to_end(t_table *table)
{
	int	i;
	int	j;
	int	status;

	i = -1;
	j = -1;
	while (++j < table->philo_n)
	{
		waitpid(0, &status, 0);
		if (WEXITSTATUS(status) == 1)
		{
			while (++i < table->philo_n)
				kill(table->philo[i]->philo_pid, SIGKILL);
		}
	}
}
