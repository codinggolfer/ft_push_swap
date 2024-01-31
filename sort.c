/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:20:21 by eagbomei          #+#    #+#             */
/*   Updated: 2024/01/26 12:26:54 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_list **stack_a, t_list **stack_b)
{
	int	pushed;
	int	size;
	int	i;

	pushed = 0;
	i = max_nbr(*stack_a);
	size = listsize(*stack_a);
	while (pushed < size / 2)
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
		if (i == (*stack_a)->value)
			ra(stack_a);
		pb(stack_a, stack_b);
		pushed++;
	}
}

static void	correct_stack_a(t_list **stack)
{
	int		min;
	int		size;
	t_list	*temp;
	int		i;

	i = 0;
	temp = *stack;
	size = listsize(*stack);
	min = min_nbr(*stack);
	while (temp)
	{
		if (min == temp->value)
			break ;
		i++;
		temp = temp->next;
	}
	if (i <= size / 2)
		while (i--)
			ra(stack);
	else if (i > size / 2)
		while (i++ != size)
			rra(stack);
}

void	sorter(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = listsize(*stack_a);
	push_to_b(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
	{
		get_pos(stack_a, stack_b);
		get_targets(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		cheapest_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		correct_stack_a(stack_a);
}
