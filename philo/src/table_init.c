/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:08:39 by jose-gon          #+#    #+#             */
/*   Updated: 2024/09/12 17:04:19 by jose-gon         ###   ########.fr       */
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

int	timestamp_filo(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->philo_n)
	{
		table->philos[i].time = get_current_time();
		table->philos[i].last_m = get_current_time();
	}
	return (0);
}

int	table_mutex_init(t_table *table)
{
	if (pthread_mutex_init(&table->m_dead, NULL))
		return (print_error(E_MUTEX_INIT));
	if (pthread_mutex_init(&table->m_print, NULL))
		return (print_error(E_MUTEX_INIT));
	return (0);
}

void	table_pointers(t_table *table, t_philo *philo)
{
	philo->m_dead = &table->m_dead;
	philo->m_print = &table->m_print;
	philo->dead_phil = &table->dead_phil;
}

int	check_nums(char *val)
{
	int	num;

	num = not_ft_atol(val);
	if (num < 0 || num > INT_MAX)
		num = -1;
	return ((int)num);
}

int	fill_philosophers(t_table *table, char **argv, int i)
{
	int	die;
	int	eat;
	int	sleep;
	int	meals;

	meals = -2;
	die = check_nums(argv[1]);
	eat = check_nums(argv[2]);
	sleep = check_nums(argv[3]);
	if (argv[4])
		meals = check_nums(argv[4]);
	if (die == -1 || eat == -1 || sleep == -1 || meals == -1)
		return (print_error(E_NUM_RANGE));
	while (++i < table->philo_n)
	{
		table->philos[i].id = i + 1;
		table->philos[i].die = die;
		table->philos[i].eat = eat;
		table->philos[i].sleep = sleep;
		table->philos[i].m_eaten = -1;
		if (argv[4])
			table->philos[i].m_eaten = meals;
		table_pointers(table, &table->philos[i]);
	}
	return (0);
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
	table->philo_n = check_nums(argv[0]);
	if (table->philo_n == -1 || table->philo_n > 200)
		return (print_error(E_NUM_P));
	table->start = 0;
	table->dead_phil = 0;
	table->philos = not_ft_calloc(table->philo_n, sizeof(t_philo));
	if (!table->philos)
		return (print_error(E_MALLOC));
	if (table_mutex_init(table))
		return (1);
	if (fill_philosophers(table, argv, -1))
		return (1);
	if (timestamp_filo(table))
		return (1);
	if (forks_init(table))
		return (1);
	return (0);
}
