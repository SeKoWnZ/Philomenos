/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:08:39 by jose-gon          #+#    #+#             */
/*   Updated: 2024/09/03 19:35:31 by jose-gon         ###   ########.fr       */
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

int	check_nums(char *val)
{
	int	num;

	num = not_ft_atol(val);
	if (num < 0 || num > INT_MAX)
		num = -1;
	return (num);
}

int	fill_philosophers(t_table *table, char **argv)
{
	int	die;
	int	eat;
	int	sleep;
	int	meals;

	die = check_nums(argv[1]);
	if (die == -1)
		return (print_error(E_NUM_RANGE));
	eat = check_nums(argv[2]);
	if (eat == -1)
		return (print_error(E_NUM_RANGE));
	sleep = check_nums(argv[3]);
	if (sleep == -1)
		return (print_error(E_NUM_RANGE));
	if (argv[4])
	{
		meals = check_nums(argv[4]);
		if (meals == -1)
			return (print_error(E_NUM_RANGE));
	}
}

int	fill_table(t_table *table, char **argv)
{
	table->philo_n = check_nums(argv[0]);
	if (table->philo_n == -1 || table->philo_n > 200)
		return (print_error(E_NUM_P));
	table->philos = not_ft_calloc(table->philo_n, sizeof(t_philo));
	if (!table->philos)
		return (print_error(E_MALLOC));
	fill_philosophers(table, argv);
}

int	check_args(char **argv)
{
	int	i;

	i = -1;
	while (argv[++i])
		if (str_isdigit(argv[i]))
			return (print_error(E_NUM));
	return (0);
}

int	table_init(t_table *table, char **argv)
{
	if (check_args(argv))
		return (1);
	if (fill_table(table, argv))
		return (1);
	return (0);
}
