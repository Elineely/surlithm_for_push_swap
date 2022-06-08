/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_last.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surlee <surlee@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:57:22 by surlee            #+#    #+#             */
/*   Updated: 2022/06/06 20:00:20 by surlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"

static void	depart_little_1(t_stack *a_stack, t_stack *b_stack, \
		int limit, int a_top)
{
	while (a_stack->top_index < limit)
	{
		if (a_stack->top_index == limit - 1 || a_stack->top_index == limit - 2)
			do_rstack(a_stack, 'a');
		else
			do_pstack(a_stack, b_stack, 'b');
	}
}

static void	depart_little_2_3(t_stack *a_stack, t_stack *b_stack, \
		int middle, int amount_c)
{
	while (a_stack->tail_index < amount_c * 4)
	{
		do_rrstack(a_stack, 'a');
		if (a_stack->top_index < middle)
		{
			do_pstack(a_stack, b_stack, 'b');
			if (b_stack->top_index < middle - amount_c / 8)
				do_rstack(b_stack, 'b');
		}
	}
	while (a_stack->top_index < middle + amount_c / 4)
	{
		if (a_stack->top_index == middle + amount_c / 4 - 1
			|| a_stack->top_index == middle + amount_c / 4 - 2)
			do_rstack(a_stack, 'a');
		else
		{
			do_pstack(a_stack, b_stack, 'b');
			if (b_stack->top_index <= middle + amount_c / 8)
				do_rstack(b_stack, 'b');
		}
	}
}

void	sort_big_last(t_stack *a_stack, t_stack *b_stack, int min, int amount_c)
{
	int	middle;
	int	a_top;

	middle = min + amount_c / 2;
	a_top = a_stack->top_index;
	while (b_stack->top_index >= min)
	{
		if (b_stack->top_index > middle - amount_c / 4)
		{
			do_pstack(b_stack, a_stack, 'a');
			if (a_stack->top_index < middle + amount_c / 4)
				do_rstack(a_stack, 'a');
		}
		else
			do_rstack(b_stack, 'b');
	}
	depart_little_1(a_stack, b_stack, min + amount_c, a_top);
	sort_b_stack(a_stack, b_stack, middle + amount_c / 4, min + amount_c - 1);
	depart_little_2_3(a_stack, b_stack, middle, amount_c);
	sort_b_stack(a_stack, b_stack, 0, a_stack->top_index - 1);
}
