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
	while (i <= count + 2) //a_stack에 3개의 원소가 남을 때까지
	{
		if (check_parted_sorted(*a_stack)) //3개 이상이 남아있는데 정렬된 상태라면 break
			break ;
		else if (a_stack->count_nums == 3) //3개가 남아있다면 sort_3로 정렬
			sort_3(a_stack);
		if (a_stack->top_index >= max - 2) //마지막 까지 남을 3개의 숫자라면 a_stack 바닥에 빼두기
			do_rstack(a_stack, 'a'); //100개 인풋을 예시로 들면 99, 98, 97은 ra
		else //마지막 까지 남을 3개의 숫자가 아니라면
		{
			do_pstack(a_stack, b_stack, 'b'); //b_stack으로 옮긴다
			if (b_stack->top_index < min + (max - min) / 2) //먼저 정렬할 구간이 아니면 rb로 바닥에 보낸다
				do_rstack(b_stack, 'b');
		}
		i++;
	}
	//현재 상태 a_stack에 3개 원소 정렬됨 or 3개 이상의 원소가 정렬된 상태(break 되서 나온 경우)
	sort_b_stack(a_stack, b_stack, min, max); //b_stack에 있는 ㄷ,ㄹ구간을 a_stack에 오름차순 정렬
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
	} //정렬이후, 의도한 구간을 넘어서는 수를 미리 바닥에 빼둔 경우, 다른 스택으로 보내기
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

	middle = (a_stack->count_nums) / 2; //input으로 들어온 수들의 중간 값
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
	} //a_stack에 ㄷ,ㄹ구간 남기고, b_stack의 top에 ㄴ구간, bottom에 ㄱ구간 보내기
	sort_a_stack(a_stack, b_stack, middle, count - 1);
	//a_stack에 존재하는 ㄷ,ㄹ구간 정렬 -> 정렬 이후 a_stack에 ㄷ,ㄹ 오름차순 정렬.
	sort_b_stack(a_stack, b_stack, middle / 2, middle);
	// b_stack의 top에 존재하는 ㄴ구간을 a_stack에 오름차순 정렬
	sort_b_stack(a_stack, b_stack, 0, middle / 2);
	//b_stack에 존재하는 ㄱ 구간을 a_stack에 오름차순 
}
