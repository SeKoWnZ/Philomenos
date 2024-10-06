/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 22:13:10 by jose-gon          #+#    #+#             */
/*   Updated: 2024/10/06 22:13:28 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	eat_routine(t_philo *philo)
{
	if (getter(philo->m_dead, philo->dead_phil))
		return (1);
	pthread_mutex_lock(philo->l_fork);
	print_queue(philo, A_FORK);
	pthread_mutex_lock(philo->r_fork);
	print_queue(philo, A_FORK);
	if (getter(philo->m_dead, philo->dead_phil))
	{
		unlock_forks(philo);
		return (1);
	}
	print_queue(philo, A_EAT);
	setter_long(philo->m_meal, &philo->last_m, get_current_time());
	if (wait_for_dead(philo, get_current_time() - philo->time, philo->eat))
	{
		unlock_forks(philo);
		return (1);
	}
	unlock_forks(philo);
	if (getter(philo->m_full, &philo->meals) != -1)
		setter(philo->m_full, &philo->meals, philo->meals - 1);
	if (getter(philo->m_full, &philo->meals) == 0)
		return (1);
	return (0);
}

int	sleep_routine(t_philo *philo)
{
	if (getter(philo->m_dead, philo->dead_phil))
		return (1);
	print_queue(philo, A_SLEEP);
	if (wait_for_dead(philo, get_current_time() - philo->time, philo->sleep))
		return (1);
	return (0);
}

void	*philosophize(void *arg)
{
	t_philo	*philo;

	philo = arg;
	if (philo->id % 2 == 0)
		precise_usleep(2);
	while (1)
	{
		if (philo->id % 2 == 0)
			usleep(50);
		if (getter(philo->m_dead, philo->dead_phil))
			return (NULL);
		if (eat_routine(philo))
			return (NULL);
		if (sleep_routine(philo))
			return (NULL);
		print_queue(philo, A_THINK);
	}
}

void	*solo_routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	pthread_mutex_lock(philo->l_fork);
	print_queue(philo, A_FORK);
	while (1)
	{
		if (getter(philo->m_dead, philo->dead_phil))
		{
			pthread_mutex_unlock(philo->l_fork);
			return (NULL);
		}
	}
}
