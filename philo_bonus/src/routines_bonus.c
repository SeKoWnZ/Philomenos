/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 23:27:32 by jose-gon          #+#    #+#             */
/*   Updated: 2024/10/06 19:40:43 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

int	eat_routine(t_philo *philo)
{
	sem_wait(philo->sem_forks);
	print_queue(philo, A_FORK);
	if (im_gona_die((get_current_time() - philo->last_m), philo->t_dead, philo))
		cleanup_n_exit(philo);
	sem_wait(philo->sem_forks);
	print_queue(philo, A_FORK);
	if (im_gona_die((get_current_time() - philo->last_m), philo->t_dead, philo))
		cleanup_n_exit(philo);
	print_queue(philo, A_EAT);
	philo->last_m = get_current_time();
	if (wait_for_dead(philo, get_current_time() - philo->time, philo->t_eat))
		cleanup_n_exit(philo);
	sem_post(philo->sem_forks);
	sem_post(philo->sem_forks);
	if (philo->max_m != -1)
		philo->max_m--;
	if (philo->max_m == 0)
		return (1);
	return (0);
}

int	sleep_routine(t_philo *philo)
{
	print_queue(philo, A_SLEEP);
	if (wait_for_dead(philo, get_current_time() - philo->time, philo->t_sleep))
		cleanup_n_exit(philo);
	return (0);
}
