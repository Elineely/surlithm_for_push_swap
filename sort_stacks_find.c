/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks_find.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surlee <surlee@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 20:16:19 by surlee            #+#    #+#             */
/*   Updated: 2022/06/06 20:19:33 by surlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"

int	find_middle_top(t_node *curr, int middle)
{
	int	i;

	i = 0;
	if (curr == NULL)
		return (0);
	while (curr->index != middle && curr->next != NULL)
	{
		curr = curr->next;
		i++;
	}
	if (curr->index != middle)
		return (0);
	return (i);
}

int	find_middle_bottom(t_node *curr, int middle)
{
	int	i;

	i = 0;
	if (curr == NULL)
		return (0);
	while (curr->index != middle && curr->prev != NULL)
	{
		curr = curr->prev;
		i++;
	}
	if (curr->index != middle)
		return (0);
	return (i);
}

int	find_middle_t_min(t_node *curr, int middle, int min)
{
	int	i;

	i = -1;
	i++;
	while (curr->index != middle && curr->next != NULL)
	{
		curr = curr->next;
		i++;
		if (curr->index < min)
			break ;
	}
	if (curr->index != middle)
		return (-1);
	return (i);
}

int	find_middle_b_min(t_node *curr, int middle, int min)
{
	int	i;

	i = -1;
	i++;
	while (curr->index != middle && curr->prev != NULL)
	{
		curr = curr->prev;
		i++;
		if (curr->index < min)
			break ;
	}
	if (curr->index != middle)
		return (-1);
	return (i);
}

int	find_middle_a_stack(t_node *curr, int middle, int max)
{
	int	i;

	i = -1;
	i++;
	while (curr->index != middle && curr->prev != NULL)
	{
		curr = curr->prev;
		i++;
	}
	if (curr->index != middle)
		return (-1);
	return (i);
}
