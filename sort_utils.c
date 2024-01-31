/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:23:09 by eagbomei          #+#    #+#             */
/*   Updated: 2024/01/24 15:59:00 by eagbomei         ###   ########.fr       */
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

void	put_index(t_list *stack, int size)
{
	t_list	*temp;
	t_list	*highest;
	int		value;

	while (--size > 0)
	{
		value = -2147483648;
		temp = stack;
		highest = NULL;
		while (temp)
		{
			if (temp->value == -2147483648 && temp->index == 0)
				temp->index = 1;
			if (temp->value > value && temp->index == 0)
			{
				value = temp->value;
				highest = temp;
			}
			temp = temp->next;
		}
		if (highest != NULL)
			highest->index = size;
	}
}

void	get_pos(t_list **stack_a, t_list **stack_b)
{
	int		i;
	t_list	*a;
	t_list	*b;

	a = *stack_a;
	b = *stack_b;
	i = 0;
	while (a)
	{
		a->pos = i;
		i++;
		a = a->next;
	}
	i = 0;
	while (b)
	{
		b->pos = i;
		i++;
		b = b->next;
	}
}
