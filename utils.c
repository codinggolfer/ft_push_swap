/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:33:30 by eagbomei          #+#    #+#             */
/*   Updated: 2024/01/16 13:58:07 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *msg)
{
	ft_putendl_fd(msg, 2);
	exit(0);
}

int	check_dup(int value, char **strs, int i)
{
	i++;
	while (strs[i])
	{
		if (ft_atol(strs[i]) == value)
			return (1);
		i++;
	}
	return (0);
}

int	is_number(char *num)
{
	int	i;

	i = 0;
	if (num[i] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

long	ft_atol(const char *str)
{
	long		mp;
	long		number;

	mp = 1;
	number = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			mp *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number *= 10;
		number += *str++ - '0';
	}
	if (number * mp > 2147483647 || number * mp < -2147483648)
		ft_error("Error");
	if (number == 0 && mp == -1)
		ft_error("Error");
	return (number * mp);
}

void	valid_arg(char **argv, int argc)
{
	int				i;
	static char		**strs;
	long			temp;

	i = 0;
	if (argc == 2)
	{
		strs = ft_split(argv[1], ' ');
		if (!strs || strs[0] == NULL)
			ft_error("Error");
	}
	else
		strs = argv;
	if (argc > 2)
		i = 1;
	while (strs[i])
	{
		temp = ft_atol(strs[i]);
		if (!is_number(strs[i]))
			ft_error("Error");
		if (check_dup(temp, strs, i) || temp < -2147483648 || temp > 2147483647)
			ft_error("Error");
		i++;
	}
}
