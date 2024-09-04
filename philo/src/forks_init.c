/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:25:16 by jose-gon          #+#    #+#             */
/*   Updated: 2024/09/04 20:10:57 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	forks_init(t_table *table)
{
	int	i;

	i = -1;
	table->fork = not_ft_calloc(table->philo_n, sizeof(pthread_mutex_t));
	if (!table->fork)
		return (print_error(E_MALLOC));
	while (++i < table->philo_n - 1)
	{
		table->philos[i].l_fork = &table->fork[i];
		table->philos[i].r_fork = &table->fork[i + 1];
	}
	table->philos[i].l_fork = &table->fork[i];
	table->philos[i].r_fork = &table->fork[0];
	return (0);
}
