/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:26:34 by jose-gon          #+#    #+#             */
/*   Updated: 2024/09/10 14:54:18 by jose-gon         ###   ########.fr       */
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
	precise_usleep(philo->eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	return (0);
}

int	sleep_routine(t_philo *philo)
{
	print_queue(philo, A_SLEEP);
	precise_usleep(philo->sleep);
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
		precise_usleep(2);
	while (1)
	{
		if (getter(philo->m_dead, philo->dead_phil))
			return (NULL);
		eat_routine(philo);
		sleep_routine(philo);
		think_routine(philo);
	}
}
