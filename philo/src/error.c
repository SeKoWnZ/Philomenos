/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:42:06 by jose-gon          #+#    #+#             */
/*   Updated: 2024/10/07 16:43:46 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	not_putstr_fd(char *s, int fd)
{
	write(fd, s, not_ft_strlen(s));
}

int	print_error(char *error)
{
	not_putstr_fd(error, 2);
	write(2, "\n", 1);
	return (1);
}

void	clean_threads(t_table *table, int i)
{
	while (i >= 0)
	{
		pthread_cancel(table->philos[i].pt);
		pthread_join(table->philos[i].pt, NULL);
		i--;
	}
}

int	safe_join(t_table *table, int *i)
{
	while (--(*i) >= 0)
	{
		if (pthread_join(table->philos[*i].pt, NULL))
			return (1);
	}
	if (pthread_join(table->pt, NULL))
		return (1);
	return (0);
}
