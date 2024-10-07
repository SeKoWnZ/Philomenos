/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_ob.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 21:09:14 by jose-gon          #+#    #+#             */
/*   Updated: 2024/10/06 02:51:44 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	philo_dead(t_table *obser, t_philo *philo, int i)
{
	if (he_gona_die((get_current_time()
				- getter_long(&obser->m_meal, &philo->last_m)), obser, i))
		return (1);
	return (0);
}

void	*watch_philos(void *arg)
{
	t_table	*obser;
	int		i;
	int		full;

	full = 0;
	obser = arg;
	i = obser->philo_n - 1;
	while (1)
	{
		if (getter(&obser->m_full, &obser->philos[i].meals) != 0)
		{
			if (philo_dead(obser, &obser->philos[i], i + 1))
				break ;
		}
		else
			full++;
		if (full == obser->philo_n)
			return (NULL);
		if (--i < 0)
		{
			i = obser->philo_n - 1;
			full = 0;
		}
	}
	return (NULL);
}
