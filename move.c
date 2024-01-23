/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:09:58 by eagbomei          #+#    #+#             */
/*   Updated: 2024/01/23 15:32:36 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rot_both(t_list **stack_a, t_list **stack_b, int a, int b)
{
	while (a < 0 && b < 0)
	{
		a++;
		b++;
		rrr(stack_a, stack_b);
	}
}

static void	rot_both(t_list **stack_a, t_list **stack_b, int a, int b)
{
	while (a > 0 && b > 0)
	{
		a--;
		b--;
		rr(stack_a, stack_b);
	}
}

static void	rotate_a(t_list **stack, int i)
{
	while (i < 0)
	{
		i++;
		rra(stack);
	}
	while (i > 0)
	{
		i--;
		ra(stack);
	}
}

static void	rotate_b(t_list **stack, int i)
{
	while (i < 0)
	{
		i++;
		rrb(stack);
	}
	while (i > 0)
	{
		i--;
		rb(stack);
	}
}

void	make_move(t_list **stack_a, t_list **stack_b, int a, int b)
{
	if (a < 0 && b < 0)
		rev_rot_both(stack_a, stack_b, a, b);
	else if (a > 0 && b > 0)
		rot_both(stack_a, stack_b, a, b);
	rotate_a(stack_a, a);
	rotate_b(stack_b, b);
	pa(stack_a, stack_b);
}
