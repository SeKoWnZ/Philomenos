/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_init_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 00:51:53 by jose-gon          #+#    #+#             */
/*   Updated: 2024/09/16 01:34:17 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

int	eat_routine(t_philo *philo)
{
		sem_wait(philo->sem_forks);
		print_queue(philo, A_FORK);
		sem_wait(philo->sem_forks);
		print_queue(philo, A_FORK);
		print_queue(philo, A_EAT);
		if (wait_for_dead(philo, get_current_time() - philo->time, philo->t_eat))
		{
			sem_post(philo->sem_forks);
			sem_post(philo->sem_forks);
			cleanup(philo);
			exit(1);
		}
		if (philo->max_m != -1)
			philo->max_m--;
		if (philo->max_m == 0)
		{
			sem_post(philo->sem_forks);
			sem_post(philo->sem_forks);
			return (1);
		}
		philo->last_m = get_current_time();
		sem_post(philo->sem_forks);
		sem_post(philo->sem_forks);
		return (0);
}	
	
int	sleep_routine(t_philo *philo)
{
	print_queue(philo, A_SLEEP);
	if (wait_for_dead(philo, get_current_time() - philo->time, philo->t_sleep))
	{
		cleanup(philo);
		exit(1);
	}
	return (0);
}

void	start_routine(t_philo *philo)
{
	while (1)
	{
		if (eat_routine(philo))
			break ;
		sleep_routine(philo);
		print_queue(philo, A_THINK);
	}
}

int	routine_init(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->philo_n)
	{
		table->philo[i]->philo_pid = fork();
		table->philo[i]->time = get_current_time();
		table->philo[i]->last_m = get_current_time();
		if (table->philo[i]->philo_pid == 0)
		{
			start_routine(table->philo[i]);
			cleanup(table->philo[i]);
			exit(0);
		}
	}
	wait_to_end(table);
	return (0);
}
