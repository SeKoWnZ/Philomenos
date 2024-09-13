/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:16:10 by jose-gon          #+#    #+#             */
/*   Updated: 2024/09/13 14:47:15 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	armageddon(t_table *table)
{
	int	i;

	if (pthread_mutex_destroy(&table->m_dead))
		print_error(E_MUTEX_DES);
	if (pthread_mutex_destroy(&table->m_print))
		print_error(E_MUTEX_DES);
	i = table->philo_n + 1;
	while (--i >= 0)
	{
		if (pthread_mutex_destroy(&table->fork[i]) != 0)
			print_error(E_MUTEX_DES);
	}
	free(table->fork);
	free(table->philos);
	return (0);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc == 5 || argc == 6)
	{
		if (table_init(&table, ++argv))
			return (1);
		if (routine_init(&table))
			return (1);
		if (armageddon(&table))
			return (1);
	}
}
