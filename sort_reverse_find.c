/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_reverse_find.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surlee <surlee@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 07:18:57 by surlee            #+#    #+#             */
/*   Updated: 2022/06/07 07:39:36 by surlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"

int	find_middle_a_stack_r(t_node *curr, int middle, int max)
{
	int	i;

	i = -1;
	i++;
	while (curr->index != middle && curr->prev != 0)
	{
		curr = curr->prev;
		i++;
	}
	if (curr->index != middle)
		return (-1);
	return (i);
}
