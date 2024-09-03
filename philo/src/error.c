/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:42:06 by jose-gon          #+#    #+#             */
/*   Updated: 2024/09/03 13:24:05 by jose-gon         ###   ########.fr       */
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
	return (1);
}
