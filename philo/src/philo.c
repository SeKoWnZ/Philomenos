/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:16:10 by jose-gon          #+#    #+#             */
/*   Updated: 2024/09/16 23:44:05 by jose-gon         ###   ########.fr       */
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
	i = -1;
	while (++i < table->philo_n)
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
	else
		print_error(E_BAD_ARGS);
}
