/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:41:18 by jose-gon          #+#    #+#             */
/*   Updated: 2024/09/17 22:57:01 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

int	main(int argc, char **argv)
{
	t_table	*table;

	table = NULL;
	if (argc == 5 || argc == 6)
	{
		if (table_init(&table, ++argv))
			return (1);
		if (routine_init(table))
			return (1);
		cleanup(table);
	}
	else
		print_error(E_BAD_ARGS);
}
