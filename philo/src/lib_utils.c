/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:59:39 by jose-gon          #+#    #+#             */
/*   Updated: 2024/09/03 14:27:39 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	*not_ft_calloc(size_t count, size_t size)
{
	void	*point;

	point = malloc(count * size);
	if (point == 0)
		return (0);
	memset(point, 0, count * size);
	return (point);
}

long	not_ft_atol(const char *str)
{
	long	final;
	long	i;
	long	negative;

	i = 0;
	negative = 1;
	final = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			negative = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		final = (str[i] - '0') + (final * 10);
		i++;
	}
	return (final * negative);
}

int	str_isdigit(char *str)
{
	if (!str)
		return (1);
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			return (*str);
		str++;
	}
	return (0);
}

int	not_ft_strlen(const	char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}
