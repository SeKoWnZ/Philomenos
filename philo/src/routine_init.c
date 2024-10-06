/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:14:34 by jose-gon          #+#    #+#             */
/*   Updated: 2024/10/06 02:47:17 by jose-gon         ###   ########.fr       */
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
	print_queue(philo, A_EAT);
	setter_long(philo->m_meal, &philo->last_m, get_current_time());
	if (wait_for_dead(philo, get_current_time() - philo->time, philo->eat))
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return (1);
	}
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
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
	// if (philo->id % 2 == 0)
	// 	precise_usleep(1);
	while (1)
	{
		if (philo->id % 2 == 1)
			precise_usleep(1);
		if (getter(philo->m_dead, philo->dead_phil))
			return (NULL);
		if (eat_routine(philo))
			return (NULL);
		if (sleep_routine(philo))
			return (NULL);
		print_queue(philo, A_THINK);
	}
}

int	routine_init(t_table *table)
{
	int	i;

	i = -1;
	timestamp_filo(table);
	if (table->philo_n == 1)
	{
		print_queue(&table->philos[0], A_FORK);
		die_anouncement(table, 1, (size_t)table->die);
		return (0);
	}
	while (++i < table->philo_n)
	{
		if (pthread_create(&table->philos[i].pt, NULL, philosophize,
				&table->philos[i]))
		{
			clean_threads(table, i);
			return (print_error(E_THREAD));
		}
	}
	if (pthread_create(&table->pt, NULL, watch_philos, table))
		return (print_error(E_THREAD));
	while (--i >= 0)
		pthread_join(table->philos[i].pt, NULL);
	pthread_join(table->pt, NULL);
	return (0);
}
