/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 17:44:25 by jose-gon          #+#    #+#             */
/*   Updated: 2024/09/17 00:30:52 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

void	fill_philo(t_table *table, char **argv, t_philo	*philo, int i)
{
	philo->id = i + 1;
	philo->t_dead = (size_t)not_ft_atol(argv[1]);
	philo->t_eat = (size_t)not_ft_atol(argv[2]);
	philo->t_sleep = (size_t)not_ft_atol(argv[3]);
	philo->max_m = -1;
	if (argv[4])
		philo->max_m = (int)not_ft_atol(argv[4]);
	philo->sem_forks = table->sem_forks;
	philo->sem_print = table->sem_print;
	philo->table = table;
}

int	semaphores_init(t_table *table)
{
	sem_unlink("forks");
	table->sem_forks = sem_open("forks", O_CREAT, 0644,
			table->philo_n);
	if (table->sem_forks == SEM_FAILED)
		return (print_error(E_SEM_INIT));
	sem_unlink("print_queue");
	table->sem_print = sem_open("print_queue", O_CREAT, 0644, 1);
	if (table->sem_print == SEM_FAILED)
	{
		sem_unlink("forks");
		return (print_error(E_SEM_INIT));
	}
	return (0);
}

int	philo_init(t_table *table, char **argv)
{
	int	i;

	if (semaphores_init(table))
		return (1);
	table->philo = not_ft_calloc(table->philo_n, sizeof(t_philo *));
	if (!table->philo)
		return (print_error(E_MALLOC));
	i = -1;
	while (++i < table->philo_n)
	{
		table->philo[i] = not_ft_calloc(1, sizeof(t_philo));
		if (!table->philo[i])
			return (error_philos(table, i), 1);
	}
	i = -1;
	while (++i < table->philo_n)
		fill_philo(table, argv, table->philo[i], i);
	return (0);
}

int	table_init(t_table **table, char **argv)
{
	if (check_args(argv))
		return (1);
	*table = not_ft_calloc(1, sizeof(t_table));
	if (!*table)
		return (1);
	(*table)->philo_n = (int)check_nums(argv[0]);
	if ((*table)->philo_n == -1 || (*table)->philo_n > 200)
	{
		free((*table));
		return (print_error(E_NUM_P));
	}
	if (philo_init((*table), argv))
	{
		free((*table));
		return (1);
	}
	return (0);
}
