/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:46:00 by eagbomei          #+#    #+#             */
/*   Updated: 2024/01/26 12:30:52 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_list *node)
{
	t_list	*temp;

	while (node)
	{
		temp = node->next;
		free(node);
		node = NULL;
		node = temp;
	}
}

t_list	*make_list(char **argv, int argc)
{
	static char		**strs;
	int				i;
	static t_list	*head = NULL;

	i = 0;
	if (argc == 2)
	{
		strs = ft_split(argv[1], ' ');
		if (!strs)
			ft_error("Error");
	}
	else
	{
		strs = argv;
		i = 1;
	}
	while (strs[i])
	{
		head = create_list(head, ft_atoi(strs[i]));
		if (!head)
			ft_error("Error");
		i++;
	}
	return (head);
}

void	parser(t_list *stack_a, t_list *stack_b)
{
	if (is_sorted(stack_a))
		return ;
	if (listsize(stack_a) == 2)
		sa(stack_a);
	if (listsize(stack_a) == 3)
		sort_three(&stack_a);
	if (listsize(stack_a) == 4)
		sort_four(&stack_a, &stack_b);
	if (listsize(stack_a) == 5)
		sort_five(&stack_a, &stack_b);
	if (listsize(stack_a) >= 6)
		sorter(&stack_a, &stack_b);
	ft_free(stack_a);
	ft_free(stack_b);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		exit (0);
	valid_arg(argv, argc);
	stack_a = make_list(argv, argc);
	stack_b = NULL;
	put_index(stack_a, listsize(stack_a) + 1);
	parser(stack_a, stack_b);
	exit (0);
}
