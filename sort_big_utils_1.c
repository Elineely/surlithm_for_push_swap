/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surlee <surlee@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:31:48 by surlee            #+#    #+#             */
/*   Updated: 2022/06/06 20:00:28 by surlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"

void	depart_2_big_part(t_stack *a_stack, t_stack *b_stack, \
		int min, int quarter)
{
	int	middle;
	int	count_a;
	int	a_top;
	int	i;

	middle = min + quarter * 2;
	count_a = a_stack->count_nums;
	a_top = a_stack->top_index;
	i = 0;
	while (a_stack->tail_index == a_top - 1 || a_stack->tail_index == a_top - 2)
	{
		do_rrstack(a_stack, 'a');
		if (a_stack->top_index > a_stack->head->next->index)
			do_sstack(a_stack, 'a');
	}
	while (b_stack->top_index < min + quarter * 4 && b_stack->top_index >= min)
	{
		if (b_stack->top_index >= middle)
			do_pstack(b_stack, a_stack, 'a');
		else
			do_rstack(b_stack, 'b');
	}
	while (a_stack->top_index != a_top)
		do_pstack(a_stack, b_stack, 'b');
}

void	sort_big_chunk_r(t_stack *a_stack, t_stack *b_stack, \
		int min, int amount_c)
{
	int	i;
	int	middle;

	middle = min + amount_c / 2;
	i = 0;
	while (i < amount_c)
	{
		if (b_stack->top_index > amount_c / 4)
		{
			do_pstack(b_stack, a_stack, 'a');
			if (a_stack->top_index >= middle + amount_c / 4)
				do_rstack(a_stack, 'a');
		}
		else
			do_rstack(b_stack, 'b');
		i++;
	}
	sort_a_stack_r(a_stack, b_stack, 0, amount_c / 4);
	depart_2_big_part_r(a_stack, b_stack, min, amount_c / 4);
	sort_b_stack_r(a_stack, b_stack, min, amount_c - 1);
}

void	sort_big_chunk(t_stack *a_stack, t_stack *b_stack, \
		int min, int amount_c)
{
	int	i;
	int	middle;

	if (check_parted_sorted(*a_stack))
		return ;
	middle = min + amount_c / 2;
	i = 0;
	while (i < amount_c && a_stack->count_nums > 1)
	{
		if (a_stack->top_index < middle + amount_c / 4)
		{
			do_pstack(a_stack, b_stack, 'b');
			if (b_stack->top_index < middle - amount_c / 4)
				do_rstack(b_stack, 'b');
		}
		else
			do_rstack(a_stack, 'a');
		i++;
	}
	if (check_parted_sorted(*a_stack))
		return ;
	sort_a_stack(a_stack, b_stack, middle + amount_c / 4, amount_c + min - 1);
	depart_2_big_part(a_stack, b_stack, min, amount_c / 4);
	sort_b_stack(a_stack, b_stack, min, a_stack->top_index - 1);
}
