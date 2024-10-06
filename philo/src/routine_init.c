/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:14:34 by jose-gon          #+#    #+#             */
/*   Updated: 2024/10/06 22:12:56 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	start_philo(t_table *table, int *i)
{
	while (++(*i) < table->philo_n)
	{
		if (pthread_create(&table->philos[*i].pt, NULL, philosophize,
				&table->philos[*i]))
			return (1);
	}
	return (0);
}

int	routine_init(t_table *table)
{
	int	i;

	i = -1;
	timestamp_filo(table);
	if (table->philo_n == 1)
	{
		i++;
		if (pthread_create(&table->philos[i].pt, NULL, solo_routine,
				&table->philos[i]))
			return (print_error(E_THREAD));
	}
	else
	{
		if (start_philo(table, &i))
		{
			clean_threads(table, i);
			return (print_error(E_THREAD));
		}
	}
	if (pthread_create(&table->pt, NULL, watch_philos, table))
		return (print_error(E_THREAD));
	if (safe_join(table, &i))
		return (print_error(E_JOIN));
	return (0);
}
