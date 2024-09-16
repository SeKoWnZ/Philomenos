/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die_protocol_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 23:59:43 by jose-gon          #+#    #+#             */
/*   Updated: 2024/09/17 00:12:54 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

int	die_anouncement(t_philo *philo, size_t t_todie)
{
	size_t	time;

	precise_usleep(t_todie);
	sem_wait(philo->sem_print);
	time = get_current_time();
	printf("%ld %d %s\n", time - philo->time, philo->id, A_DEAD);
	sem_post(philo->sem_print);
	return (1);
}

size_t	im_gona_die(size_t duration, size_t t_val)
{
	if (duration > t_val)
		return (duration - t_val);
	return (0);
}

int	wait_for_dead(t_philo *philo, size_t st, size_t ms)
{
	size_t	end;
	size_t	el_time;
	size_t	d_time;

	end = get_current_time() - philo->time;
	el_time = end - st;
	while (el_time < ms)
	{
		precise_usleep(1);
		end = get_current_time() - philo->time;
		el_time = end - st;
		d_time = im_gona_die((get_current_time() - philo->last_m), philo->t_dead);
		if (d_time)
			return (die_anouncement(philo, d_time));
	}
	return (0);
}
