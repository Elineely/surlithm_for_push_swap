/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_middle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surlee <surlee@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:38:15 by surlee            #+#    #+#             */
/*   Updated: 2022/06/06 20:27:09 by surlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"

int	get_middle_from_ends(t_stack *a_stack, t_stack *b_stack, int *middle)
{
	if (b_stack->top_index != *middle && b_stack->tail_index != *middle)
		return (0);
	if (b_stack->top_index == *middle)
		do_pstack(b_stack, a_stack, 'a');
	else
	{
		do_rrstack(b_stack, 'b');
		do_pstack(b_stack, a_stack, 'a');
	}
	*middle = a_stack->top_index - 1;
	return (1);
}
