/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:41:35 by jose-gon          #+#    #+#             */
/*   Updated: 2024/10/03 20:16:25 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <unistd.h>
# include <semaphore.h>

typedef struct s_table	t_table;

typedef struct s_philo
{
	pid_t	philo_pid;
	int		id;
	int		max_m;
	size_t	t_dead;
	size_t	t_eat;
	size_t	t_sleep;
	size_t	time;
	size_t	last_m;
	sem_t	*sem_forks;
	sem_t	*sem_print;
	t_table	*table;
}			t_philo;

typedef struct s_table
{
	int		philo_n;
	sem_t	*sem_forks;
	sem_t	*sem_print;
	t_philo	**philo;
}			t_table;

// ERRORS

# define E_NUM "Error: Only numeric values accepted"
# define E_NUM_P "Error: Invalid number of Philosophers"
# define E_NUM_RANGE "Error: Invalid numeric input range"
# define E_MALLOC "Error: Malloc memory problem!"
# define E_SEM_INIT "Error: Semaphore unable to init"
# define E_TIME "Error: Get time failed"
# define E_BAD_ARGS "Error: Bad number of args"
# define E_FORK "Error: Fork creation fail!"

// ANOUNCEMENTS

# define A_EAT "is eating"
# define A_FORK "has taken a fork"
# define A_SLEEP "is sleeping"
# define A_THINK "is thinking"
# define A_DEAD "died"

// CHECKS

int		check_args(char **argv);
long	check_nums(char *val);

// INIT

int		table_init(t_table **table, char **argv);
int		routine_init(t_table *table);

// ROUTINE

int		sleep_routine(t_philo *philo);
int		eat_routine(t_philo *philo);
int		die_anouncement(t_philo *philo, size_t t_todie);
void	wait_to_end(t_table *table);
int		precise_usleep(size_t ms);
size_t	im_gona_die(size_t duration, size_t t_val, t_philo *philo);

// NOT LIB

void	*not_ft_calloc(size_t count, size_t size);
long	not_ft_atol(const char *str);
int		str_isdigit(char *str);
int		not_ft_strlen(const char *s);

// UTILS

size_t	get_current_time(void);
void	print_queue(t_philo *philo, char *msg);
int		wait_for_dead(t_philo *philo, size_t st, size_t ms);
void	cleanup(t_table *table);
int		p_fork(void);

// ERROR

void	not_putstr_fd(char *s, int fd);
int		print_error(char *error);
int		error_philos(t_table *table, int num);

#endif
