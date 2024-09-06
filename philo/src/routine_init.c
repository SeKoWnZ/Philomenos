/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:14:34 by jose-gon          #+#    #+#             */
/*   Updated: 2024/09/06 19:55:27 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	clean_threads(t_table *table, int i)
{
	while (i >= 0)
	{
		pthread_cancel(table->philos[i].pt);
		pthread_join(table->philos[i].pt, NULL);
		i--;
	}
}

int	threads_creation(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->philo_n)
	{
		if (pthread_create(&table->philos[i].pt, NULL, philosophize, &table->philos[i]))
		{
			clean_threads(table, i);
			return (print_error(E_THREAD));
		}
	}
	setter(table, &table->m_table, 1);
	usleep(2000);
	setter(table, &table->m_table, -1);
	return (0);
}
