/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surlee <surlee@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:16:39 by surlee            #+#    #+#             */
/*   Updated: 2022/06/06 17:19:33 by surlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"

int	check_sorted(t_stack a_stack)
{
	t_node	*curr;

	if (a_stack.top_index == -1)
		return (1);
	curr = a_stack.head;
	if (a_stack.top_index != 0)
		return (0);
	curr = curr->next;
	while (curr != NULL)
	{
		if (curr->index != curr->prev->index + 1)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	check_parted_sorted(t_stack a_stack)
{
	t_node	*curr;

	if (a_stack.top_index == -1)
		return (1);
	curr = a_stack.head->next;
	while (curr != NULL)
	{
		if (curr->index != curr->prev->index + 1)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	check_parted_sorted_r(t_stack b_stack)
{
	t_node	*curr;

	if (b_stack.top_index == -1)
		return (1);
	curr = b_stack.head->next;
	while (curr != NULL)
	{
		if (curr->index != curr->prev->index - 1)
			return (0);
		curr = curr->next;
	}
	return (1);
}
