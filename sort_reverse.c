/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_reverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surlee <surlee@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:04:30 by surlee            #+#    #+#             */
/*   Updated: 2022/06/06 20:11:21 by surlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"

void	sort_3_r(t_stack *b_stack)
{
	if (b_stack->top_index == 0)
	{
		do_rstack(b_stack, 'b');
		if (b_stack->top_index != 2)
			do_sstack(b_stack, 'b');
	}
	else if (b_stack->tail_index == 2)
		do_rrstack(b_stack, 'b');
	else
	{
		do_sstack(b_stack, 'b');
		if (b_stack->top_index == 0)
			do_rstack(b_stack, 'b');
	}
}

void	sort_a_stack_r(t_stack *a_stack, t_stack *b_stack, int min, int max)
{
	while (b_stack->count_nums > 3)
	{
		if (check_parted_sorted_r(*b_stack))
			break ;
		if (b_stack->top_index <= min + 2)
			do_rstack(b_stack, 'b');
		else
		{
			do_pstack(b_stack, a_stack, 'a');
			if (a_stack->top_index < min + (max - min) / 2)
				do_rstack(a_stack, 'a');
		}
	}
	while (check_parted_sorted_r(*b_stack) == 0)
	{
		if (min == 0)
			sort_3_r(b_stack);
	}
	sort_b_stack_r(a_stack, b_stack, min, max);
}

static void	take_remainders_r(t_stack *b_stack)
{
	if (b_stack->tail_index == b_stack->top_index + 1)
		do_rrstack(b_stack, 'b');
}

void	sort_b_stack_r(t_stack *a_stack, t_stack *b_stack, int min, int max)
{
	int	middle;
	int	i;
	int	j;

	middle = b_stack->top_index + 1;
	while (middle <= max && b_stack->count_nums)
	{
		if (get_from_bstack_r(a_stack, b_stack, &middle, max))
			continue ;
		i = find_middle_t_min(a_stack->head, middle, min);
		j = find_middle_b_min(a_stack->tail, middle, min);
		if (i == 0 || j == 0)
			get_middle_from_ends_r(a_stack, b_stack, &middle);
		else if (i == -1 || (j != -1 && j < i))
			get_m_bottom_r(a_stack, b_stack, &middle, max);
		else
			get_m_top_r(a_stack, b_stack, &middle, max);
	}
	take_remainders_r(b_stack);
}

void	depart_2_big_part_r(t_stack *a_stack, t_stack *b_stack, \
		int min, int quarter)
{
	int	middle;
	int	count_b;
	int	b_top;
	int	i;

	middle = min + quarter * 2;
	count_b = b_stack->count_nums;
	b_top = b_stack->top_index;
	i = 0;
	while (a_stack->tail_index == b_top + 1 || a_stack->tail_index == b_top + 2)
	{
		do_rrstack(b_stack, 'b');
		if (b_stack->top_index < b_stack->head->next->index)
			do_sstack(b_stack, 'b');
	}
	while (a_stack->top_index < min + quarter * 2)
	{
		if (a_stack->top_index >= middle)
			do_rstack(a_stack, 'a');
		else
			do_pstack(a_stack, b_stack, 'b');
	}
	while (b_stack->top_index != b_top)
		do_pstack(b_stack, a_stack, 'a');
}
