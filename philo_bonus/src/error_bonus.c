/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 20:09:39 by jose-gon          #+#    #+#             */
/*   Updated: 2024/09/16 01:39:05 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

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

int	error_philos(t_table *table, int num)
{
	int	i;

	i = -1;
	while (num > ++i)
		free(table->philo[i]);
	free(table->philo);
	return (print_error(E_MALLOC));
}
