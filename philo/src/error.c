/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:42:06 by jose-gon          #+#    #+#             */
/*   Updated: 2024/09/04 15:58:45 by jose-gon         ###   ########.fr       */
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
