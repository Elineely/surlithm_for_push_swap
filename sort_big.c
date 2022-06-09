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
	move_second_chunk(a, b, amount_c); //b_stack에 ㄱ 구간만 남기고 ㄴ구간을 a_stack 위 아래에 2개 구간으로 나누기
	sort_big_chunk_r(a, b, 0, amount_c); //b_stack에 있는 ㄱ 구간 내림차순 정렬
	sort_b_stack_r(a, b, amount_c, amount_c * 2); //a_stack에 존재하는 ㄴ구간을 b_stack에 내림 차순 정렬하기
	//현재 a_stack에는 정렬되지 않은채 혼합되어있는 ㄷ,ㄹ,ㅁ 구간 존재, b_stack엔 내림차순 정렬된 ㄴ,ㄱ구간 존재.
	depart_3_chunk(a, b, amount_c, count_t); //a_stack에 ㅁ구간을 남기고, ㄷ구간은 b의 top으로, ㄹ구간은 b의 bottom으로
	sort_big_chunk(a, b, amount_c * 4, count_t - amount_c * 4); // a_stack에 혼자 남은 ㅁ구간을 오름차순 정렬
	depart_third_chunk(a, b, amount_c); //b의 top에 있는 ㄷ 구간을 a의 top과 bottom에 ㄷ구간의 중간값 보다 큰 수 작은수로 구간 나누기.
	sort_b_stack_r(a, b, amount_c * 2, amount_c * 3 - 1); //a에 존재하는 ㄷ구간을 b)stack에 내림 차순 정렬
	//현재 a_stack에는 정렬된 ㅁ 구간, b_stack의 top에는 ㄷ,ㄴ,ㄱ순으로 내림차순되어있고 bottom에 ㄹ 구간 존재.
	depart_forth_chunk(a, b, amount_c); //ㄹ 구간을 astack으로 옮김
	sort_big_last(a, b, amount_c * 3, amount_c); // ㄹ 구간을 정렬하는데 최소 명령어를 쓸수 있게 b에 구간을 조금 더 잘게 나눈후,
	//a_stack에 오름차순 정렬 & b에 내림차순으로 정렬된 수들도 다 a 스택으로 옮김. 
}

void	sort_stacks_big(t_stack *a_stack, t_stack *b_stack)
{
	int		i;
	int		count_t;
	int		count_c;
	int		amount_c;

	count_t = a_stack->count_nums;
	amount_c = get_amount_c(count_t); //5구간으로 나눌수 있는 적정한 청크크기 설정
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
	} //모든 인풋을 검사해서 a_stack에는 ㄷ,ㄹ,ㅁ 구간을 남기고, b_stack의 top쪽에 ㄴ구간, bottom쪽에 ㄱ구간으로 분리 
	divide_and_sort(a_stack, b_stack, amount_c, count_t);
}
