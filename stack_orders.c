/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_orders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surlee <surlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:18:38 by surlee            #+#    #+#             */
/*   Updated: 2022/06/07 09:41:55 by surlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"
#include "push_swap.h"

void	do_pstack(t_stack *from, t_stack *to, char name_of_to)
{
	if (from->count_nums == 0)
		return ;
	push_front(to, pop_front(from));
	if (name_of_to == 'a')
		ft_putstr_fd("pa\n", 1);
	else if (name_of_to == 'b')
		ft_putstr_fd("pb\n", 1);
}

void	do_rstack(t_stack *stack, char name_of_stack)
{
	if (stack->count_nums == 0)
		return ;
	push_back(stack, pop_front(stack));
	if (name_of_stack == 'a')
		ft_putstr_fd("ra\n", 1);
	else if (name_of_stack == 'b')
		ft_putstr_fd("rb\n", 1);
}

void	do_rrstack(t_stack *stack, char name_of_stack)
{
	if (stack->count_nums == 0)
		return ;
	push_front(stack, pop_back(stack));
	if (name_of_stack == 'a')
		ft_putstr_fd("rra\n", 1);
	else if (name_of_stack == 'b')
		ft_putstr_fd("rrb\n", 1);
}

void	do_sstack(t_stack *stack, char name_of_stack)
{
	t_node	*node_1st;
	t_node	*node_2nd;

	if (stack->count_nums < 2)
		return ;
	node_1st = pop_front(stack);
	node_2nd = pop_front(stack);
	push_front(stack, node_1st);
	push_front(stack, node_2nd);
	if (name_of_stack == 'a')
		ft_putstr_fd("sa\n", 1);
	else if (name_of_stack == 'b')
		ft_putstr_fd("sb\n", 1);
}
