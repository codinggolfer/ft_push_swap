/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:46:00 by eagbomei          #+#    #+#             */
/*   Updated: 2024/01/11 17:34:00 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	valid_arg(char **argv, int argc)
{
	int			i;
	static char	**strs;
	long		temp;

	i = 0;
	if (argc == 2)
	{
		strs = ft_split(argv[1], ' ');
		if (!strs)
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

t_list	*make_list(char **argv, int argc)
{
	static char			**strs;
	int					i;
	static t_list		*head = NULL;

	i = 0;
	if (argc == 2)
	{
		strs = ft_split(argv[1], ' ');
		if (!strs)
			ft_error("Error");
	}
	else
	{
		strs = argv;
		i = 1;
	}
	while (strs[i])
	{
		head = create_list(head, ft_atoi(strs[i]));
		if (!head)
			ft_error("Error");
		i++;
	}
	return (head);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (0);
	valid_arg(argv, argc);
	stack_a = make_list(argv, argc);
	// while (stack_a)
	// {
	// 	printf("stack a:%d\n", stack_a->value);
	// 	stack_a = stack_a->next;
	// }
	// while (stack_b)
	// {
	// 	printf("stack b:%d\n", stack_b->value);
	// 	stack_b = stack_b->next;
	// }
	return (0);
}
