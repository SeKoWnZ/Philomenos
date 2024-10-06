/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_init_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 00:51:53 by jose-gon          #+#    #+#             */
/*   Updated: 2024/10/06 19:44:29 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

void	start_routine(t_philo *philo)
{
	while (1)
	{
		if (philo->id % 2 == 0)
			usleep(50);
		if (eat_routine(philo))
			break ;
		sleep_routine(philo);
		print_queue(philo, A_THINK);
	}
}

void	solo_routine(t_table *table)
{
	table->philo[0]->philo_pid = p_fork();
	table->philo[0]->time = get_current_time();
	if (table->philo[0]->philo_pid == 0)
	{
		print_queue(table->philo[0], A_FORK);
		die_anouncement(table->philo[0], table->philo[0]->t_dead);
		cleanup(table);
		exit (1);
	}
}

void	multiple_routine(t_table *table)
{
	int		i;
	size_t	time;

	i = -1;
	time = get_current_time();
	while (++i < table->philo_n)
	{
		table->philo[i]->philo_pid = p_fork();
		table->philo[i]->time = time;
		table->philo[i]->last_m = get_current_time();
		if (table->philo[i]->philo_pid == 0)
		{
			start_routine(table->philo[i]);
			cleanup(table);
			exit(0);
		}
		usleep(100);
	}
}

int	routine_init(t_table *table)
{
	if (table->philo_n == 1)
		solo_routine(table);
	else
		multiple_routine(table);
	wait_to_end(table);
	return (0);
}
