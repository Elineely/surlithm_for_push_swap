/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surlee <surlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 18:09:37 by surlee            #+#    #+#             */
/*   Updated: 2022/06/07 09:30:25 by surlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"

void	find_min_max(t_stack *a_stack, int *min, int *max)
{
	int		i;
	t_node	*curr;

	i = 0;
	curr = a_stack->head;
	while (i < 3)
	{
		if (curr->index > *max)
			*max = curr->index;
		if (curr->index < *min)
			*min = curr->index;
		i++;
		curr = curr->next;
	}
}

int	find_4or5_top(t_stack *a_stack, t_node *curr, int middle)
{
	int	i;

	i = 0;
	while (curr->index != middle)
	{
		if (i == a_stack->count_nums - 1 && curr->index != middle)
			return (0);
		curr = curr->next;
		i++;
	}
	return (i);
}

void	pick_4and5(t_stack *a_stack, t_stack *b_stack)
{
	int	i;
	int	j;

	while (a_stack->count_nums > 3)
	{
		if (a_stack->top_index > 2)
			do_pstack(a_stack, b_stack, 'b');
		else if (a_stack->tail->index > 2)
		{
			do_rrstack(a_stack, 'a');
			do_pstack(a_stack, b_stack, 'b');
		}
		else
		{
			i = find_4or5_top(a_stack, a_stack->head, 4);
			j = find_4or5_top(a_stack, a_stack->head, 3);
			if ((j == 0 && a_stack->top_index == 3)
				|| (i == 0 && a_stack->top_index == 4))
				continue ;
			if (i > 2)
				do_rrstack(a_stack, 'a');
			else
				do_rstack(a_stack, 'a');
		}
	}
}
