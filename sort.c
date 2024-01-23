/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:20:21 by eagbomei          #+#    #+#             */
/*   Updated: 2024/01/23 16:30:39 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_list **stack_a, t_list **stack_b)
{
	int	pushed;
	int	size;

	pushed = 0;
	size = listsize(*stack_a);
	while (size >= 6 && pushed < size / 2)
	{
		if ((*stack_a)->index <= size / 2)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
	}
	while (size - pushed > 3)
	{
		pb(stack_a, stack_b);
		pushed++;
	}
}

void	sorter(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = listsize(*stack_a);
	push_to_b(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
	{
		get_targets(stack_a, stack_b);
		get_pos(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		cheapest_move(stack_a, stack_b);
	}
	// get_targets(stack_a, stack_b);
	// get_pos(stack_a, stack_b);
	// get_cost(stack_a, stack_b);
	// cheapest_move(stack_a, stack_b);

	// get_targets(stack_a, stack_b);
	// get_pos(stack_a, stack_b);
	// get_cost(stack_a, stack_b);
	// cheapest_move(stack_a, stack_b);

	// get_targets(stack_a, stack_b);
	// get_pos(stack_a, stack_b);
	// get_cost(stack_a, stack_b);
	// cheapest_move(stack_a, stack_b);
	while (*stack_a)
	{
		printf("stack a:%d -->", (*stack_a)->value);
		printf("stack index: %d\n", (*stack_a)->index);
		*stack_a = (*stack_a)->next;
	}
	// while (*stack_b)
	// {
	// 	printf("stack b:%d", (*stack_b)->value);
	// 	printf("--> index:  %d\n", (*stack_b)->target);
	// 	*stack_b = (*stack_b)->next;
	// }
}
