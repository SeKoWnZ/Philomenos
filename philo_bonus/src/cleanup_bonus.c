/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 00:20:30 by jose-gon          #+#    #+#             */
/*   Updated: 2024/09/16 01:33:51 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

void	cleanup(t_philo *philo)
{
	t_table *tmp;
	int		i;

	i = -1;
	tmp = philo->table;
	while (++i < tmp->philo_n)
		free(tmp->philo[i]);
	free(tmp->philo);
	free(tmp);
}

void	wait_to_end(t_table *table)
{
	int	i;
	int	status;

	i = -1;
	waitpid(0, &status, 0);
	if (WIFEXITED(status) == 1)
	{
		while (++i > table->philo_n)
			kill(table->philo[i]->philo_pid, SIGKILL);
	}
}