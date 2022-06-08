/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surlee <surlee@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:59:55 by surlee            #+#    #+#             */
/*   Updated: 2022/06/06 18:06:35 by surlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"

static int	get_amount_c(int count_t)
{
	if (count_t < 122)
		return (20);
	if (count_t < 162)
		return (30);
	else if (count_t < 202)
		return (40);
	else if (count_t < 252)
		return (50);
	else if (count_t < 302)
		return (60);
	else if (count_t < 352)
		return (70);
	else if (count_t < 402)
		return (80);
	else if (count_t < 452)
		return (90);
	else
		return (100);
}

static void	divide_and_sort(t_stack *a, t_stack *b, int amount_c, int count_t)
{
	move_second_chunk(a, b, amount_c);
	sort_big_chunk_r(a, b, 0, amount_c);
	sort_b_stack_r(a, b, amount_c, amount_c * 2);
	depart_3_chunk(a, b, amount_c, count_t);
	sort_big_chunk(a, b, amount_c * 4, count_t - amount_c * 4);
	depart_third_chunk(a, b, amount_c);
	sort_b_stack_r(a, b, amount_c * 2, amount_c * 3 - 1);
	depart_forth_chunk(a, b, amount_c);
	sort_big_last(a, b, amount_c * 3, amount_c);
}

void	sort_stacks_big(t_stack *a_stack, t_stack *b_stack)
{
	int		i;
	int		count_t;
	int		count_c;
	int		amount_c;

	count_t = a_stack->count_nums;
	amount_c = get_amount_c(count_t);
	count_c = count_t / amount_c;
	if (count_c % amount_c)
		count_c++;
	i = 0;
	while (i < count_t)
	{
		if (a_stack->top_index < 2 * amount_c)
		{
			do_pstack(a_stack, b_stack, 'b');
			if (b_stack->top_index < amount_c)
				do_rstack(b_stack, 'b');
		}
		else
			do_rstack(a_stack, 'a');
		i++;
	}
	divide_and_sort(a_stack, b_stack, amount_c, count_t);
}
