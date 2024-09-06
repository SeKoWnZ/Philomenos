/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:26:34 by jose-gon          #+#    #+#             */
/*   Updated: 2024/09/06 19:55:16 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	print_queue(pthread_mutex_t *mute, char *str, int i)
{
	pthread_mutex_lock(mute);
	printf("%s%d\n", str, i);
	pthread_mutex_unlock(mute);
}

void	*philosophize(void *arg)
{
	t_philo	*phil;
	int		val;

	phil = arg;
	while (1)
	{
		if (phil->id % 2 == 0)
			usleep(4324);
		val = getter(&phil->table->m_table, &phil->table->start);
		if (val == 1)
			print_queue(&phil->table->m_print, "HOLA SOY:", phil->id);
		else if (val == -1)
			return (NULL);
	}
}
