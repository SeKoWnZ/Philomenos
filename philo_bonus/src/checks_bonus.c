/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-gon <jose-gon@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 17:46:16 by jose-gon          #+#    #+#             */
/*   Updated: 2024/10/08 13:42:37 by jose-gon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

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
		if (check_nums(argv[i]) == -1)
			return (print_error(E_NUM_RANGE));
	}
	return (0);
}

long	check_nums(char *val)
{
	long	num;

	num = not_ft_atol(val);
	if (num < 0 || num > INT_MAX)
		num = -1;
	return (num);
}
