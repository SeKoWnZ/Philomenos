/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:53:46 by jose-gon          #+#    #+#             */
/*   Updated: 2024/10/03 20:27:09 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	die_anouncement(t_philo *philo, size_t t_todie)
{
	size_t	time;

	precise_usleep(t_todie);
	pthread_mutex_lock(philo->m_print);
	pthread_mutex_lock(philo->m_dead);
	if (*philo->dead_phil == 1)
	{
		pthread_mutex_unlock(philo->m_dead);
		pthread_mutex_unlock(philo->m_print);
		return (1);
	}
	*philo->dead_phil = 1;
	time = get_current_time();
	printf("%ld %d %s\n", time - philo->time, philo->id, A_DEAD);
	pthread_mutex_unlock(philo->m_dead);
	pthread_mutex_unlock(philo->m_print);
	return (1);
}

size_t	im_gona_die(size_t duration, size_t t_val, t_philo *philo)
{
	if (duration > t_val)
		die_anouncement(philo, duration - t_val);
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
		if (im_gona_die((get_current_time() - philo->last_m),
				philo->die, philo))
			return (1);
	}
	return (0);
}
