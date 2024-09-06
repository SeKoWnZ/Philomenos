/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_n_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:41:41 by jose-gon          #+#    #+#             */
/*   Updated: 2024/09/06 18:45:25 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	getter(pthread_mutex_t *mute, int *value)
{
	int	ret;

	pthread_mutex_lock(mute);
	ret = *value;
	pthread_mutex_unlock(mute);
	return (ret);
}

void	setter(t_table *table, pthread_mutex_t *mute, int val)
{
	pthread_mutex_lock(mute);
	table->start = val;
	pthread_mutex_unlock(mute);
}
