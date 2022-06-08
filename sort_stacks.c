/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surlee <surlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 17:25:27 by surlee            #+#    #+#             */
/*   Updated: 2022/06/07 09:35:40 by surlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"

void	sort_a_stack(t_stack *a_stack, t_stack *b_stack, int min, int max)
{
	int	count;
	int	i;

	count = max - min;
	i = 0;
	while (i <= count + 2)
	{
		if (check_parted_sorted(*a_stack))
			break ;
		else if (a_stack->count_nums == 3)
			sort_3(a_stack);
		if (a_stack->top_index >= max - 2)
			do_rstack(a_stack, 'a');
		else
		{
			do_pstack(a_stack, b_stack, 'b');
			if (b_stack->top_index < min + (max - min) / 2)
				do_rstack(b_stack, 'b');
		}
		i++;
	}
	sort_b_stack(a_stack, b_stack, min, max);
}

static void	take_remainders(t_stack *a_stack, t_stack *b_stack, int max)
{
	while (a_stack->tail_index == a_stack->top_index - 1
		|| a_stack->tail_index == a_stack->top_index - 2
		|| a_stack->tail_index == 0 || a_stack->tail_index == 1)
	{
		do_rrstack(a_stack, 'a');
		if (a_stack->top_index > a_stack->head->next->index)
			do_sstack(a_stack, 'a');
	}
	if (b_stack->top_index == max)
	{
		do_pstack(b_stack, a_stack, 'a');
		do_rstack(a_stack, 'a');
	}
}

void	sort_b_stack(t_stack *a_stack, t_stack *b_stack, int min, int max)
{
	int	middle;
	int	i;
	int	j;

	if (a_stack->count_nums > 1)
	{
		while (a_stack->top_index != a_stack->head->next->index - 1)
			do_rstack(a_stack, 'a');
	}
	middle = a_stack->top_index - 1;
	while (middle >= min && b_stack->count_nums)
	{
		if (get_from_astack(a_stack, b_stack, &middle, max))
			continue ;
		i = find_middle_t_min(b_stack->head, middle, min);
		j = find_middle_b_min(b_stack->tail, middle, min);
		if (i == 0 || j == 0)
			get_middle_from_ends(a_stack, b_stack, &middle);
		else if (i == -1 || (j != -1 && j < i))
			get_m_bottom(a_stack, b_stack, &middle, max);
		else
			get_m_top(a_stack, b_stack, &middle, max);
	}
	take_remainders(a_stack, b_stack, max);
}

void	sort_stacks(t_stack *a_stack, t_stack *b_stack)
{
	unsigned int	middle;
	int				i;
	int				count;

	middle = (a_stack->count_nums) / 2;
	count = a_stack->count_nums;
	i = 0;
	while (i < count)
	{
		if (a_stack->top_index < middle)
		{
			do_pstack(a_stack, b_stack, 'b');
			if (b_stack->top_index < middle / 2)
				do_rstack(b_stack, 'b');
		}
		else
			do_rstack(a_stack, 'a');
		i++;
	}
	sort_a_stack(a_stack, b_stack, middle, count - 1);
	sort_b_stack(a_stack, b_stack, middle / 2, middle);
	sort_b_stack(a_stack, b_stack, 0, middle / 2);
}
