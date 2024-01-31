/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagbomei <eagbomei@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:18:25 by eagbomei          #+#    #+#             */
/*   Updated: 2024/01/26 11:50:37 by eagbomei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct s_list
{
	int				pos;
	int				value;
	int				target;
	int				index;
	int				cost_b;
	int				cost_a;
	struct s_list	*next;
}	t_list;

void	valid_arg(char **argv, int argc);
void	ft_error(char *msg);
int		is_number(char *num);
void	ft_free(t_list *node);
int		check_dup(int value, char **strs, int i);
long	ft_atol(const char *str);
t_list	*make_list(char **argv, int argc);
t_list	*create_list(t_list *head, int value);
t_list	*new_list(int value);
int		listsize(t_list *head);
t_list	*listlast(t_list *head);
void	sa(t_list *stack_a);
void	sb(t_list *stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ss(t_list *stack_a, t_list *stack_b);
void	rra(t_list **stack);
void	rrr(t_list **stack_a, t_list **stack_b);
void	rrb(t_list **stack);
void	ra(t_list **stack);
void	rb(t_list **stack);
void	rr(t_list **stack_a, t_list **stack_b);
void	sort_two(t_list **head);
void	sort_three(t_list **head);
void	sort_four(t_list **stack_a, t_list **stack_b);
void	sort_five(t_list **stack_a, t_list **stack_b);
void	parser(t_list *stack_a, t_list *stack_b);
int		is_sorted(t_list *stack);
int		max_nbr(t_list *stack);
int		min_nbr(t_list *stack);
void	put_index(t_list *stack, int size);
void	sorter(t_list **stack_a, t_list **stack_b);
void	get_targets(t_list **stack_a, t_list **stack_b);
void	push_to_b(t_list **stack_a, t_list **stack_b);
void	get_cost(t_list **stack_a, t_list **stack_b);
void	get_pos(t_list **stack_a, t_list **stack_b);
void	cheapest_move(t_list **stack_a, t_list **stack_b);
void	make_move(t_list **stack_a, t_list **stack_b, int a, int b);

#endif