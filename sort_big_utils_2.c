/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surlee <surlee@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:35:08 by surlee            #+#    #+#             */
/*   Updated: 2022/06/06 20:00:39 by surlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"

void	move_second_chunk(t_stack *a, t_stack *b, int amount_c)
{
	while (b->top_index >= amount_c)
	{
		do_pstack(b, a, 'a');
		if (a->top_index >= amount_c + amount_c / 2)
			do_rstack(a, 'a');
	}
}

void	depart_3_chunk(t_stack *a, t_stack *b, int amount_c, int count_t)
{
	while (b->tail_index != 0)
	{
		do_rrstack(b, 'b');
		if (b->top_index - 1 != b->head->next->index)
			do_pstack(b, a, 'a');
	}
	while (a->count_nums > count_t - amount_c * 4 && a->count_nums > 1)
	{
		if (a->top_index >= amount_c * 4)
			do_rstack(a, 'a');
		else
		{
			do_pstack(a, b, 'b');
			if (b->top_index >= amount_c * 3)
				do_rstack(b, 'b');
		}
	}
}

void	depart_third_chunk(t_stack *a, t_stack *b, int amount_c)
{
	while (b->top_index >= amount_c * 2)
	{
		do_pstack(b, a, 'a');
		if (a->top_index >= amount_c * 2 + amount_c / 2)
			do_rstack(a, 'a');
	}
	while (b->top_index >= amount_c * 3)
		do_rstack(b, 'b');
}

void	depart_forth_chunk(t_stack *a, t_stack *b, int amount_c)
{
	while (b->tail_index >= amount_c * 3)
	{
		do_rrstack(b, 'b');
		if (b->top_index >= amount_c * 3 + amount_c / 4)
		{
			do_pstack(b, a, 'a');
			if (a->top_index < amount_c * 4 - amount_c / 4)
				do_rstack(a, 'a');
		}
	}
}
