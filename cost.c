/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 09:41:34 by eagbomei          #+#    #+#             */
/*   Updated: 2024/01/23 16:18:39 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	target_index(t_list **stack, int b_targ)
{
	t_list	*a;
	int		i;

	i = 0;
	a = *stack;
	while (a)
	{
		if (a->index == b_targ)
			break ;
		i++;
		a = a->next;
	}
	return (i);
}

void	get_cost(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_b;
	int		size_b;
	int		size_a;

	size_a = listsize(*stack_a);
	size_b = listsize(*stack_b);
	temp_b = *stack_b;
	while (temp_b)
	{
		temp_b->cost_b = temp_b->pos;
		if (temp_b->pos > size_b / 2)
			temp_b->cost_b = (size_b - temp_b->pos) * -1;
		temp_b->cost_a = target_index(stack_a, temp_b->target);
		if (temp_b->cost_a > size_a / 2)
			temp_b->cost_a = (size_a - temp_b->cost_a) * -1;
		temp_b = temp_b->next;
	}
}

int	abs(int i)
{
	if (i < 0)
		return (i * -1);
	return (i);
}

void	cheapest_move(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	temp = *stack_b;
	cheapest = 2147483647;
	while (temp)
	{
		if (abs(temp->cost_a) + abs(temp->cost_b) < abs(cheapest))
		{
			cheapest = abs(temp->cost_a) + abs(temp->cost_b);
			cost_a = temp->cost_a;
			cost_b = temp->cost_b;
		}
		temp = temp->next;
	}
	make_move(stack_a, stack_b, cost_a, cost_b);
}
