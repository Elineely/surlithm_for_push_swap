/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surlee <surlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:30:08 by surlee            #+#    #+#             */
/*   Updated: 2022/06/07 09:43:27 by surlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_utils.h"
#include "push_swap.h"

void	init_stack(t_stack *stack)
{
	stack->head = NULL;
	stack->tail = NULL;
	stack->top_index = -1;
	stack->tail_index = -1;
	stack->count_nums = 0;
}

t_node	*make_a_node(int content, int *arr4i, int i_amount)
{
	t_node	*new;
	int		i;

	new = malloc(sizeof(t_node));
	if (new == 0)
		return (0);
	new->content = content;
	i = 0;
	while (i < i_amount)
	{
		if (arr4i[i] == content)
		{
			new->index = i;
			break ;
		}
		i++;
	}
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	put2stack(t_stack *a_s, char *str, unsigned int count, int *arr4i)
{
	int			j;
	static int	k;

	j = 0;
	while (str[j] == ' ')
		j++;
	while (str[j] != '\0')
	{
		if (ft_strchr(&str[j], ' ') == 0)
			push_back(a_s, make_a_node(ft_atoi(&str[j]), arr4i, count));
		else
			push_back(a_s, make_a_node(ft_atoi(ft_substr(str, j, (ft_strchr
								(&str[j], ' ') - (&str[j])))), arr4i, count));
		if (ft_strchr(&str[j], ' ') == 0)
			return ;
		j = ft_strchr(&str[j], ' ') - (&str[0]);
		while (str[j] == ' ')
			j++;
	}
}
