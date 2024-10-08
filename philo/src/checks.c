/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 14:25:53 by jose-gon          #+#    #+#             */
/*   Updated: 2024/10/08 13:39:55 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	check_args(char **argv)
{
	int	i;

	i = -1;
	while (argv[++i])
	{
		if (str_isdigit(argv[i]))
		{
			if (str_isdigit(argv[i]) == '-')
				return (print_error(E_NUM_RANGE));
			else
				return (print_error(E_NUM));
		}
	}
	return (0);
}

int	check_nums(char *val)
{
	long	num;

	num = not_ft_atol(val);
	if (num < 0 || num > INT_MAX)
		num = -1;
	return ((int)num);
}
