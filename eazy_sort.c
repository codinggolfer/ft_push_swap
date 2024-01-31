/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eazy_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:15:50 by eagbomei          #+#    #+#             */
/*   Updated: 2024/01/26 12:18:29 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list **head)
{
	if ((*head)->value == (*head)->next->value)
		sa(*head);
	return ;
}

void	sort_three(t_list **head)
{
	t_list	*temp;

	if (is_sorted(*head))
		return ;
	temp = listlast(*head);
	if ((*head)->value < (*head)->next->value)
	{
		rra(head);
		if (is_sorted(*head))
			return ;
		sa(*head);
	}
	if ((*head)->value < temp->value)
		sa(*head);
	if ((*head)->value > (*head)->next->value)
	{
		ra(head);
		if (!is_sorted(*head))
			sa(*head);
	}
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	int		min;

	min = min_nbr(*stack_a);
	while (stack_a)
	{
		if (min == (*stack_a)->value)
		{
			pb(stack_a, stack_b);
			break ;
		}
		if (min == (*stack_a)->next->value)
			ra(stack_a);
		else
			rra(stack_a);
	}
	if (!is_sorted(*stack_a))
		sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int		min;

	min = min_nbr(*stack_a);
	while (stack_a)
	{
		if (min == (*stack_a)->value)
		{
			pb(stack_a, stack_b);
			break ;
		}
		if (min == (*stack_a)->next->value)
			ra(stack_a);
		else
			rra(stack_a);
	}
	if (!is_sorted(*stack_a))
		sort_four(stack_a, stack_b);
	pa(stack_a, stack_b);
}
