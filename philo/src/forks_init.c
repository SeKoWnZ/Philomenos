/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:25:16 by jose-gon          #+#    #+#             */
/*   Updated: 2024/10/06 20:56:11 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	create_forks(t_table *table)
{
	int	i;

	i = -1;
	table->fork = not_ft_calloc(table->philo_n, sizeof(pthread_mutex_t));
	if (!table->fork)
		return (print_error(E_MALLOC));
	while (++i < table->philo_n)
	{
		if (pthread_mutex_init(&table->fork[i], NULL))
		{
			while (i >= 0)
				pthread_mutex_destroy(&table->fork[i]);
			return (free(table->fork), print_error(E_MUTEX_INIT));
		}
	}
	return (0);
}

int	forks_init(t_table *table)
{
	int	i;
	int	num;

	num = table->philo_n;
	if (create_forks(table))
		return (1);
	i = -1;
	while (++i < table->philo_n)
	{
		if (i % 2 == 0)
		{
			table->philos[i].l_fork = &table->fork[i];
			table->philos[i].r_fork = &table->fork[(i + 1) % num];
		}
		else
		{
			table->philos[i].l_fork = &table->fork[(i + 1) % num];
			table->philos[i].r_fork = &table->fork[i];
		}
	}
	return (0);
}
