/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:53:46 by jose-gon          #+#    #+#             */
/*   Updated: 2024/09/11 19:34:54 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	die_anouncement(t_philo *philo, size_t t_todie)
{
	size_t	time;

	precise_usleep(t_todie);
	time = get_current_time();
	if (!getter(philo->m_dead, philo->dead_phil))
	{
		pthread_mutex_lock(philo->m_print);
		setter(philo->m_dead, philo->dead_phil, 1);
		printf("%ld %d %s\n", time - philo->time, philo->id, A_DEAD);
		pthread_mutex_unlock(philo->m_print);
	}
}

int	im_gona_die(size_t duration, int *t_val)
{
	if (duration > *t_val)
		return (*t_val - duration);
	return (0);
}

int	wait_for_dead(t_philo *philo, size_t st, size_t ms)
{
	size_t	end;
	size_t	el_time;
	int		d_time;

	end = get_current_time() - philo->time;
	el_time = end - st;
	while (el_time <= ms)
	{
		if (getter(philo->m_dead, philo->dead_phil))
			return (1);
		precise_usleep(1);
		end = get_current_time() - philo->time;
		el_time = end - st;
		d_time = im_gona_die(el_time, philo->die);
		if (d_time)
		{
			die_anouncement(philo, d_time);
			return (1);
		}
	}
	return (0);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (print_error(E_TIME));
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	precise_usleep(size_t ms)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < ms)
		usleep(500);
	return (0);
}

void	print_queue(t_philo *philo, char *msg)
{
	size_t	time;

	time = get_current_time();
	pthread_mutex_lock(philo->m_print);
	if (!getter(philo->m_dead, philo->dead_phil))
		printf("%ld %d %s\n", time - philo->time, philo->id, msg);
	pthread_mutex_unlock(philo->m_print);
}
