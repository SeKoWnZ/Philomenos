/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:08:39 by jose-gon          #+#    #+#             */
/*   Updated: 2024/09/13 14:26:40 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

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
