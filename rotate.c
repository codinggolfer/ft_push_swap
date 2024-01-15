/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:31:30 by eagbomei          #+#    #+#             */
/*   Updated: 2024/01/12 16:22:42 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*last;

	last = listlast(*stack);
	temp = *stack;
	*stack = temp->next;
	temp->next = NULL;
	last->next = temp;
}

void	ra(t_list **stack_a)
{
	if (listsize(*stack_a) < 2)
		return ;
	rotate(stack_a);
	ft_putendl_fd("ra", 1);
}

void	rb(t_list **stack_b)
{
	if (listsize(*stack_b) < 2)
		return ;
	rotate(stack_b);
	ft_putendl_fd("rb", 1);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	if (listsize(*stack_a) < 2 || listsize(*stack_b) < 2)
		return ;
	rotate(stack_a);
	rotate(stack_b);
	ft_putendl_fd("rr", 1);
}