/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:08:39 by jose-gon          #+#    #+#             */
/*   Updated: 2024/09/02 18:41:03 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

// ◦ number_of_philosophers: The number of philosophers and also the number
//   of forks.
// ◦ time_to_die (in milliseconds): If a philosopher didn’t start eating 
//	 time_to_die milliseconds since the beginning of their last meal or 
//	 the beginning of the simulation, they die.
// ◦ time_to_eat (in milliseconds): The time it takes for a philosopher to eat.
//   During that time, they will need to hold two forks.
// ◦ time_to_sleep (in milliseconds): The time a philosopher will spend 
//   sleeping.
// ◦ number_of_times_each_philosopher_must_eat (optional argument): If all
//   philosophers have eaten at least number_of_times_each_philosopher_must_eat
//   times, the simulation stops. If not specified, the simulation stops when a
//   philosopher dies.

int	table_init(t_table *table, char **argv)
{
	(void)table;
	(void)argv;
	return (0);
}
