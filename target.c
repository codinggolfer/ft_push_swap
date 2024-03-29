/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:40:55 by eagbomei          #+#    #+#             */
/*   Updated: 2024/01/26 11:42:49 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_targets(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp_a;
	t_list	*temp_b;

	temp_a = *stack_a;
	temp_b = *stack_b;
	while (temp_b)
	{
		while (temp_a)
		{
			if (temp_b->index < temp_a->index
				&& temp_b->target > temp_a->index)
				temp_b->target = temp_a->index;
			temp_a = temp_a->next;
		}
		temp_a = *stack_a;
		temp_b = temp_b->next;
	}
}
