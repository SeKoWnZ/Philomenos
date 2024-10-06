/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:53:46 by jose-gon          #+#    #+#             */
/*   Updated: 2024/10/06 02:42:30 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	die_anouncement(t_table *obser, int i, size_t t_todie)
{
	size_t	time;

	precise_usleep(t_todie);
	pthread_mutex_lock(&obser->m_print);
	pthread_mutex_lock(&obser->m_dead);
	obser->dead_phil = 1;
	time = get_current_time();
	printf("%ld %d %s\n", time - (size_t)obser->time, i, A_DEAD);
	pthread_mutex_unlock(&obser->m_dead);
	pthread_mutex_unlock(&obser->m_print);
}

int	he_gona_die(size_t duration, t_table *obser, int i)
{
	if (duration > (size_t)obser->die)
	{
		die_anouncement(obser, i, duration - obser->die);
		return (1);
	}
	return (0);
}

int	wait_for_dead(t_philo *philo, size_t st, size_t ms)
{
	size_t	end;
	size_t	el_time;

	end = get_current_time() - philo->time;
	el_time = end - st;
	while (el_time < ms)
	{
		if (getter(philo->m_dead, philo->dead_phil))
			return (1);
		precise_usleep(1);
		end = get_current_time() - philo->time;
		el_time = end - st;
	}
	return (0);
}
