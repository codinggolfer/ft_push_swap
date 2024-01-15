/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:23:09 by eagbomei          #+#    #+#             */
/*   Updated: 2024/01/15 15:51:19 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack)
{
	int	val;

	val = stack->value;
	while (stack)
	{
		if (val > stack->value)
			return (0);
		val = stack->value;
		stack = stack->next;
	}
	return (1);
}

int	max_nbr(t_list *stack)
{
	int	i;

	i = stack->value;
	while (stack)
	{
		if (i < stack->value)
			i = stack->value;
		stack = stack->next;
	}
	return (i);
}

int	min_nbr(t_list *stack)
{
	int	i;

	i = stack->value;
	while (stack)
	{
		if (i > stack->value)
			i = stack->value;
		stack = stack->next;
	}
	return (i);
}