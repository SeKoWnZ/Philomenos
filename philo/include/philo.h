/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:21:32 by jose-gon          #+#    #+#             */
/*   Updated: 2024/09/02 18:39:58 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>

typedef struct s_philo
{
	int		id;
	int		m_eaten;
}			t_philo;	

typedef struct s_table
{
	int			philo_n;
	int			meals;
	int			sleep;
	pthread_t	*philos;
}				t_table;

// INIT FUNCTIONS

int		table_init(t_table *table, char **argv);

// LIB UTILS

long	ft_atol(const char *str);

#endif
