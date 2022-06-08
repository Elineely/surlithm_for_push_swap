/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_reverse_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surlee <surlee@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:10:23 by surlee            #+#    #+#             */
/*   Updated: 2022/06/07 07:27:55 by surlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"

int	get_middle_from_ends_r(t_stack *a_stack, t_stack *b_stack, int *middle)
{
	if (a_stack->top_index != *middle && a_stack->tail_index != *middle)
		return (0);
	if (a_stack->top_index == *middle)
		do_pstack(a_stack, b_stack, 'b');
	else
	{
		do_rrstack(a_stack, 'a');
		do_pstack(a_stack, b_stack, 'b');
	}
	*middle = b_stack->top_index + 1;
	return (1);
}

int	get_from_bstack_r(t_stack *a_stack, t_stack *b_stack, int *middle, int max)
{
	if (find_middle_a_stack_r(b_stack->tail, *middle, max) != -1)
	{
		while (b_stack->tail_index != *middle)
		{
			do_rrstack(b_stack, 'b');
			do_pstack(b_stack, a_stack, 'a');
		}
		if (b_stack->tail_index == *middle)
		{
			do_rrstack(b_stack, 'b');
			(*middle)++;
			return (1);
		}
	}
	return (0);
}

static void	save_next_middle_r(t_stack *a_stack, t_stack *b_stack, int middle)
{
	if (a_stack->top_index == middle + 2 \
			|| a_stack->top_index == middle + 3)
	{
		do_pstack(a_stack, b_stack, 'b');
		do_rstack(b_stack, 'b');
	}
}

void	get_m_top_r(t_stack *a, t_stack *b, int *middle, int max)
{
	while (b->top_index != *middle)
	{
		if (a->count_nums == 1)
		{
			do_pstack(a, b, 'b');
			break ;
		}
		if (get_from_bstack_r(a, b, middle, max))
			return ;
		save_next_middle_r(a, b, *middle);
		if (a->top_index == *middle || a->top_index == *middle + 1)
		{
			do_pstack(a, b, 'b');
			if (b->top_index == *middle + 1)
				continue ;
			if (b->top_index < b->head->next->index)
				do_sstack(b, 'b');
			if (b->top_index == *middle || b->top_index == *middle + 1)
			{
				*middle = b->top_index + 1;
				return ;
			}
		}
		do_rstack(a, 'a');
	}
}

void	get_m_bottom_r(t_stack *a, t_stack *b, int *middle, int max)
{
	while (b->top_index != *middle)
	{
		if (a->count_nums == 1)
		{
			do_pstack(a, b, 'b');
			break ;
		}
		if (get_from_bstack_r(a, b, middle, max))
			return ;
		save_next_middle_r(a, b, *middle);
		if (a->top_index == *middle || a->top_index == *middle + 1)
		{
			do_pstack(a, b, 'b');
			if (b->top_index == *middle + 1)
				continue ;
			if (b->top_index < b->head->next->index)
				do_sstack(b, 'b');
			if (b->top_index == *middle || b->top_index == *middle + 1)
			{
				*middle = b->top_index + 1;
				return ;
			}
		}
		do_rrstack(a, 'a');
	}
}
