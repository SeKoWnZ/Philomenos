/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 23:27:32 by jose-gon          #+#    #+#             */
/*   Updated: 2024/09/17 23:32:35 by jose-gon         ###   ########.fr       */
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
		cleanup(philo->table);
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
		cleanup(philo->table);
		exit(1);
	}
	return (0);
}
