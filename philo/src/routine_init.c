/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:14:34 by jose-gon          #+#    #+#             */
/*   Updated: 2024/09/12 17:05:00 by jose-gon         ###   ########.fr       */
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
	while (--i >= 0)
		pthread_join(table->philos[i].pt, NULL);
	return (0);
}
