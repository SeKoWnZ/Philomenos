/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:21:32 by jose-gon          #+#    #+#             */
/*   Updated: 2024/09/15 17:57:19 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <errno.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				die;
	int				eat;
	int				sleep;
	int				m_eaten;
	size_t			last_m;
	size_t			time;
	int				*dead_phil;
	pthread_t		pt;
	pthread_mutex_t	*m_dead;
	pthread_mutex_t	*m_print;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
}					t_philo;

typedef struct s_table
{
	int				philo_n;
	int				dead_phil;
	t_philo			*philos;
	pthread_mutex_t	m_dead;
	pthread_mutex_t	m_print;
	pthread_mutex_t	*fork;
}					t_table;

// ERRORS

# define E_NUM "Error: Only numeric values accepted"
# define E_NUM_P "Error: Invalid number of Philosophers"
# define E_NUM_RANGE "Error: Invalid numeric input range"
# define E_MALLOC "Error: Malloc memory problem!"
# define E_MUTEX_INIT "Error: Mutex unable to init"
# define E_MUTEX_DES "Error: Destroying mutex"
# define E_THREAD "Error: Thread creation failed"
# define E_TIME "Error: Get time failed"

// ANOUNCEMENTS

# define A_EAT "is eating"
# define A_FORK "has taken a fork"
# define A_SLEEP "is sleeping"
# define A_THINK "is thinking"
# define A_DEAD "died"

// ROUTINES

int				eat_routine(t_philo *philo);
int				sleep_routine(t_philo *philo);
int				think_routine(t_philo *philo);
void			*philosophize(void *argv);
void			print_queue(t_philo *philo, char *msg);
int				precise_usleep(size_t ms);
int				wait_for_dead(t_philo *philo, size_t st, size_t ms);

// CHECKS N GETS

int				getter(pthread_mutex_t *mute, int *val);
void			setter(pthread_mutex_t *mute, int *val, int new);
size_t			get_current_time(void);

// INIT FUNCTIONS

int				routine_init(t_table *table);
int				table_init(t_table *table, char **argv);
int				forks_init(t_table *table);

// ERROR HANDLE

void			clean_threads(t_table *table, int i);
int				print_error(char *error);

// LIB UTILS

int				str_isdigit(char *str);
int				not_ft_strlen(const char *s);
int				check_args(char **argv);
int				check_nums(char *val);
long			not_ft_atol(const char *str);
void			*not_ft_calloc(size_t count, size_t size);

#endif
