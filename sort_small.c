/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surlee <surlee@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:55:52 by surlee            #+#    #+#             */
/*   Updated: 2022/06/06 18:01:34 by surlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"

void	sort_4and5(t_stack *a_stack, t_stack *b_stack)
{
	pick_4and5(a_stack, b_stack);
	if (b_stack->top_index == 4)
		do_sstack(b_stack, 'b');
	sort_under_3(a_stack, b_stack, a_stack->count_nums);
	while (b_stack->top_index == 3 || b_stack->top_index == 4)
	{
		do_pstack(b_stack, a_stack, 'a');
		do_rstack(a_stack, 'a');
	}
}

void	sort_under_3(t_stack *a_stack, t_stack *sort_b_stack, int count)
{
	if (check_sorted(*a_stack))
		return ;
	if (count == 2)
		do_sstack(a_stack, 'a');
	else if (a_stack->top_index == 2)
	{
		do_rstack(a_stack, 'a');
		if (a_stack->top_index == 1)
			do_sstack(a_stack, 'a');
	}
	else if (a_stack->tail->index == 0)
		do_rrstack(a_stack, 'a');
	else
	{
		do_sstack(a_stack, 'a');
		if (a_stack->top_index == 2)
			do_rstack(a_stack, 'a');
	}
}

void	sort_3(t_stack *a_stack)
{
	int		max;
	int		min;

	max = a_stack->top_index;
	min = a_stack->top_index;
	find_min_max(a_stack, &min, &max);
	if (a_stack->top_index == max)
	{
		do_rstack(a_stack, 'a');
		if (a_stack->top_index != min)
			do_sstack(a_stack, 'a');
	}
	else if (a_stack->tail_index == min)
		do_rrstack(a_stack, 'a');
	else
	{
		do_sstack(a_stack, 'a');
		if (a_stack->top_index == max)
			do_rstack(a_stack, 'a');
	}
}
