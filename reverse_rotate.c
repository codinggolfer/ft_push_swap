/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:22:34 by eagbomei          #+#    #+#             */
/*   Updated: 2024/01/11 15:31:01 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*lstnode;

	lstnode = listlast(*stack);
	temp = *stack;
	while (temp)
	{
		if (temp->next->next == NULL)
		{
			temp->next = NULL;
			break ;
		}
		temp = temp->next;
	}
	lstnode->next = *stack;
	(*stack) = lstnode;
}

void	rra(t_list **stack)
{
	if (listsize(*stack) < 2)
		return ;
	reverse_rotate(stack);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_list **stack)
{
	if (listsize(*stack) < 2)
		return ;
	reverse_rotate(stack);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	if (listsize(*stack_a) < 2 || listsize(*stack_b) < 2)
		return ;
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
}

