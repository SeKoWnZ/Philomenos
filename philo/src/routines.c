/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:26:34 by jose-gon          #+#    #+#             */
/*   Updated: 2024/09/12 18:56:00 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	eat_routine(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_queue(philo, A_FORK);
	pthread_mutex_lock(philo->r_fork);
	print_queue(philo, A_FORK);
	print_queue(philo, A_EAT);
	if (wait_for_dead(philo, get_current_time() - philo->time, philo->eat))
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return (1);
	}
	if (philo->m_eaten != -1)
		philo->m_eaten--;
	if (philo->m_eaten == 0)
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return (1);
	}
	philo->last_m = get_current_time();
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	return (0);
}

int	sleep_routine(t_philo *philo)
{
	print_queue(philo, A_SLEEP);
	if (wait_for_dead(philo, get_current_time() - philo->time, philo->sleep))
		return (1);
	return (0);
}

int	think_routine(t_philo *philo)
{
	print_queue(philo, A_THINK);
	return (0);
}

void	*philosophize(void *arg)
{
	t_philo	*philo;

	philo = arg;
	if (philo->id % 2 == 0)
		precise_usleep(1);
	while (1)
	{
		if (getter(philo->m_dead, philo->dead_phil))
			return (NULL);
		if (eat_routine(philo))
			return (NULL);
		if (getter(philo->m_dead, philo->dead_phil))
			return (NULL);
		if (sleep_routine(philo))
			return (NULL);
		think_routine(philo);
	}
}
