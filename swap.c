/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 10:55:17 by eagbomei          #+#    #+#             */
/*   Updated: 2024/01/22 14:07:10 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swapper(t_list *stack)
{
	t_list	*temp;
	int		temp_content;

	temp = stack->next;
	temp_content = stack->value;
	stack->value = temp->value;
	temp->value = temp_content;
	temp_content = stack->next->index;
	temp->index = stack->index;
	stack->index = temp_content;
}

void	sa(t_list *stack_a)
{
	if (listsize(stack_a) < 2)
		return ;
	swapper(stack_a);
	ft_putendl_fd("sa", 1);
}

void	sb(t_list *stack_b)
{
	if (listsize(stack_b) < 2)
		return ;
	swapper(stack_b);
	ft_putendl_fd("sb", 1);
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	if (listsize(stack_a) < 2 || listsize(stack_b) < 2)
		return ;
	swapper(stack_a);
	swapper(stack_b);
	ft_putendl_fd("ss", 1);
}

