/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:21:32 by jose-gon          #+#    #+#             */
/*   Updated: 2024/09/06 19:36:25 by jose-gon         ###   ########.fr       */
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

typedef struct s_table t_table;

typedef struct s_philo
{
	int				id;
	int				die;
	int				eat;
	int				sleep;
	int				m_eaten;
	pthread_t		pt;
	t_table			*table;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
}					t_philo;

typedef struct s_table
{
	int				philo_n;
	int				start;
	int				dead_phil;
	t_philo			*philos;
	pthread_mutex_t	m_table;
	pthread_mutex_t	m_print;
	pthread_mutex_t	*fork;
}					t_table;

// ERRORS

# define E_NUM "Error: Only numeric values accepted"
# define E_NUM_P "Error: Invalid number of Philosophers"
# define E_NUM_RANGE "Error: Invalid numeric input range"
# define E_MALLOC "Error: Malloc memory problem!"
# define E_MUTEX_INIT "Error: Mutex unable to init"
# define E_THREAD "Error: Thread creation failed"

// ROUTINES

void			*philosophize(void *argv);

// CHECKS N GETS

int				getter(pthread_mutex_t *mute, int *val);
void			setter(t_table *table, pthread_mutex_t *mute, int val);

// INIT FUNCTIONS

int				threads_creation(t_table *table);
int				table_init(t_table *table, char **argv);
int				forks_init(t_table *table);

// ERROR HANDLE

void			clean_threads(t_table *table, int i);
int				print_error(char *error);

// LIB UTILS

int				str_isdigit(char *str);
int				not_ft_strlen(const char *s);
long			not_ft_atol(const char *str);
void			*not_ft_calloc(size_t count, size_t size);

// TEST

void			printtable(t_table *table);

#endif
