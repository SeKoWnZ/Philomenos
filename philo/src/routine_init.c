/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:14:34 by jose-gon          #+#    #+#             */
/*   Updated: 2024/09/13 14:45:45 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

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
		if (sleep_routine(philo))
			return (NULL);
		think_routine(philo);
	}
}

int	routine_init(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->philo_n)
	{
		if (pthread_create(&table->philos[i].pt, NULL, philosophize,
				&table->philos[i]))
		{
			clean_threads(table, i);
			return (print_error(E_THREAD));
		}
	}
	while (--i >= 0)
		pthread_join(table->philos[i].pt, NULL);
	return (0);
}
