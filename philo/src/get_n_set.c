/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_n_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:41:41 by jose-gon          #+#    #+#             */
/*   Updated: 2024/10/06 00:38:38 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

size_t	getter_long(pthread_mutex_t *mute, size_t *value)
{
	size_t	ret;

	pthread_mutex_lock(mute);
	ret = *value;
	pthread_mutex_unlock(mute);
	return (ret);
}

void	setter_long(pthread_mutex_t *mute, size_t *val, size_t new)
{
	pthread_mutex_lock(mute);
	*val = new;
	pthread_mutex_unlock(mute);
}

int	getter(pthread_mutex_t *mute, int *value)
{
	int	ret;

	pthread_mutex_lock(mute);
	ret = *value;
	pthread_mutex_unlock(mute);
	return (ret);
}

void	setter(pthread_mutex_t *mute, int *val, int new)
{
	pthread_mutex_lock(mute);
	*val = new;
	pthread_mutex_unlock(mute);
}
