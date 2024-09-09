/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 13:26:34 by jose-gon          #+#    #+#             */
/*   Updated: 2024/09/09 18:58:07 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

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
	printf("%ld %d %s\n", time - philo->time, philo->id, msg);
	pthread_mutex_unlock(philo->m_print);
}

int	eat_routine(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_queue(philo, A_FORK);
	pthread_mutex_lock(philo->r_fork);
	print_queue(philo, A_FORK);
	print_queue(philo, A_EAT);
	precise_usleep(philo->eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	return (0);
}

void	*philosophize(void *arg)
{
	t_philo	*philo;

	philo = arg;
	if (philo->id % 2 == 0)
		precise_usleep(10);
	while (1)
	{
		if (getter(philo->m_dead, philo->dead_phil))
			return (NULL);
		eat_routine(philo);
		precise_usleep()
	}
}
