/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:08:39 by jose-gon          #+#    #+#             */
/*   Updated: 2024/10/06 02:49:16 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	timestamp_filo(t_table *table)
{
	size_t	time;
	int		i;

	time = get_current_time();
	table->time = time;
	i = -1;
	while (++i < table->philo_n)
	{
		table->philos[i].time = time;
		table->philos[i].last_m = time;
	}
	return (0);
}

int	table_mutex_init(t_table *table)
{
	if (pthread_mutex_init(&table->m_dead, NULL))
		return (print_error(E_MUTEX_INIT));
	if (pthread_mutex_init(&table->m_print, NULL))
	{
		pthread_mutex_destroy(&table->m_dead);
		return (print_error(E_MUTEX_INIT));
	}
	if (pthread_mutex_init(&table->m_meal, NULL))
	{
		pthread_mutex_destroy(&table->m_dead);
		pthread_mutex_destroy(&table->m_print);
		return (print_error(E_MUTEX_INIT));
	}
	if (pthread_mutex_init(&table->m_full, NULL))
	{
		pthread_mutex_destroy(&table->m_dead);
		pthread_mutex_destroy(&table->m_print);
		pthread_mutex_destroy(&table->m_meal);
		return (print_error(E_MUTEX_INIT));
	}
	return (0);
}

void	table_pointers(t_table *table, t_philo *philo)
{
	philo->m_dead = &table->m_dead;
	philo->m_print = &table->m_print;
	philo->m_meal = &table->m_meal;
	philo->m_full = &table->m_full;
	philo->dead_phil = &table->dead_phil;
}

int	fill_philosophers(t_table *table, char **argv, int i)
{
	int	meals;

	meals = -2;
	table->die = check_nums(argv[1]);
	table->eat = check_nums(argv[2]);
	table->sleep = check_nums(argv[3]);
	if (argv[4])
		meals = check_nums(argv[4]);
	if (table->die == -1 || table->eat == -1
		|| table->sleep == -1 || meals == -1)
		return (print_error(E_NUM_RANGE));
	while (++i < table->philo_n)
	{
		table->philos[i].id = i + 1;
		table->philos[i].die = table->die;
		table->philos[i].eat = table->eat;
		table->philos[i].sleep = table->sleep;
		table->philos[i].meals = -1;
		if (argv[4])
			table->philos[i].meals = meals;
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
	table->dead_phil = 0;
	table->philos = not_ft_calloc(table->philo_n, sizeof(t_philo));
	if (!table->philos)
		return (print_error(E_MALLOC));
	if (table_mutex_init(table))
		return (free(table->philos), 1);
	if (fill_philosophers(table, argv, -1))
		return (free(table->philos), 1);
	if (forks_init(table))
		return (free(table->philos), 1);
	return (0);
}
