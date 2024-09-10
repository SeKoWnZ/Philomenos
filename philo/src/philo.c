/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:16:10 by jose-gon          #+#    #+#             */
/*   Updated: 2024/09/10 18:32:15 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	main(int argc, char **argv)
{
	t_table		table;

	if (argc == 5 || argc == 6)
	{
		if (table_init(&table, ++argv))
			return (1);
		//printtable(&table);
		threads_creation(&table);
		//clean_threads(&table, table.philo_n);
		//routine_init(&table);
		free(table.philos);
	}
}
