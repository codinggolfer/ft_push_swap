/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:52:05 by eagbomei          #+#    #+#             */
/*   Updated: 2024/01/11 17:32:36 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (!stack_a)
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	if (!stack_b)
	{
		temp->next = NULL;
		*stack_b = temp;
	}
	else
	{
		temp->next = *stack_b;
		*stack_b = temp;
	}
	ft_putendl_fd("pb", 1);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (!stack_b)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	if (!stack_a)
	{
		temp->next = NULL;
		*stack_a = temp;
	}
	else
	{
		temp->next = *stack_a;
		*stack_a = temp;
	}
	ft_putendl_fd("pa", 1);
}