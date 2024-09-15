/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 22:37:49 by jose-gon          #+#    #+#             */
/*   Updated: 2024/09/16 00:04:14 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

int	p_fork(void)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		return (-1);
	return (pid);
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
		usleep(20);
	return (0);
}

void	print_queue(t_philo *philo, char *msg)
{
	size_t	time;

	time = get_current_time();
	sem_wait(philo->sem_print);
	printf("%ld %d %s\n", time - philo->time, philo->id, msg);
	sem_post(philo->sem_print);
}