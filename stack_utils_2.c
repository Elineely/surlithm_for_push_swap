/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surlee <surlee@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 18:59:15 by surlee            #+#    #+#             */
/*   Updated: 2022/05/25 12:37:01 by surlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"

void	push_front(t_stack *stack, t_node *new_top)
{
	if (!new_top)
		return ;
	new_top->next = stack->head;
	if (stack->head != NULL)
		stack->head->prev = new_top;
	else
		stack->tail = new_top;
	stack->head = new_top;
	(stack->count_nums)++;
	stack->top_index = stack->head->index;
	stack->tail_index = stack->tail->index;
	return ;
}

void	push_back(t_stack *stack, t_node *new_back)
{
	if (!new_back)
		return ;
	new_back->prev = stack->tail;
	if (stack->head != NULL)
		stack->tail->next = new_back;
	else
	{
		stack->head = new_back;
		stack->top_index = stack->head->index;
	}
	stack->tail = new_back;
	stack->tail_index = stack->tail->index;
	(stack->count_nums)++;
	return ;
}

t_node	*pop_front(t_stack *stack)
{
	t_node	*return_node;

	return_node = stack->head;
	if (stack->head && stack->head->next)
	{
		stack->head = stack->head->next;
		stack->head->prev = NULL;
		return_node->next = NULL;
		stack->top_index = stack->head->index;
	}
	else
	{
		stack->head = NULL;
		stack->tail = NULL;
		stack->top_index = -1;
		stack->tail_index = -1;
	}
	(stack->count_nums)--;
	return (return_node);
}

t_node	*pop_back(t_stack *stack)
{
	t_node	*return_node;

	return_node = stack->tail;
	if (stack->tail->prev != NULL)
	{
		stack->tail = stack->tail->prev;
		stack->tail->next = NULL;
		return_node->prev = NULL;
	}
	else
	{
		stack->head = NULL;
		stack->tail = NULL;
		stack->top_index = -1;
		stack->tail_index = -1;
	}
	(stack->count_nums)--;
	return (return_node);
}
