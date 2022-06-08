/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks_get.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surlee <surlee@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 20:19:59 by surlee            #+#    #+#             */
/*   Updated: 2022/06/07 07:36:53 by surlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"

int	get_from_astack(t_stack *a_stack, t_stack *b_stack, int *middle, int max)
{
	if (find_middle_a_stack(a_stack->tail, *middle, max) != -1)
	{
		while (a_stack->tail_index != *middle)
		{
			do_rrstack(a_stack, 'a');
			do_pstack(a_stack, b_stack, 'b');
		}
		if (a_stack->tail_index == *middle)
		{
			do_rrstack(a_stack, 'a');
			(*middle)--;
			return (1);
		}
	}
	return (0);
}

static void	save_next_middle(t_stack *a_stack, t_stack *b_stack, int middle)
{
	if (b_stack->top_index == middle - 2 \
		|| b_stack->top_index == middle - 3)
	{
		do_pstack(b_stack, a_stack, 'a');
		do_rstack(a_stack, 'a');
	}
}

void	get_m_top(t_stack *a, t_stack *b, int *middle, int max)
{
	while (a->top_index != *middle)
	{
		if (b->count_nums == 1)
		{
			do_pstack(b, a, 'a');
			break ;
		}
		if (get_from_astack(a, b, middle, max))
			return ;
		save_next_middle(a, b, *middle);
		if (b->top_index == *middle || b->top_index == *middle - 1)
		{
			do_pstack(b, a, 'a');
			if (a->top_index == *middle - 1)
				continue ;
			if (a->top_index > a->head->next->index)
				do_sstack(a, 'a');
			if (a->top_index == *middle || a->top_index == *middle - 1)
			{
				*middle = a->top_index - 1;
				return ;
			}
		}
		do_rstack(b, 'b');
	}
}

void	get_m_bottom(t_stack *a, t_stack *b, int *middle, int max)
{
	while (a->top_index != *middle)
	{
		if (b->count_nums == 1)
		{
			do_pstack(b, a, 'a');
			break ;
		}
		if (get_from_astack(a, b, middle, max))
			return ;
		save_next_middle(a, b, *middle);
		if (b->top_index == *middle || b->top_index == *middle - 1)
		{
			do_pstack(b, a, 'a');
			if (a->top_index == *middle - 1)
				continue ;
			if (a->top_index > a->head->next->index)
				do_sstack(a, 'a');
			if (a->top_index == *middle || a->top_index == *middle - 1)
			{
				*middle = a->top_index - 1;
				return ;
			}
		}
		do_rrstack(b, 'b');
	}
}
