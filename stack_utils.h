/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surlee <surlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:01:08 by surlee            #+#    #+#             */
/*   Updated: 2022/06/07 11:33:05 by surlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_UTILS_H
# define STACK_UTILS_H

# include <stdlib.h>

typedef struct s_node
{
	int				content;
	unsigned int	index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		top_index;
	int		tail_index;
	int		count_nums;
}	t_stack_struct;

typedef t_stack_struct	t_stack;

/*   stack_utils_1.c    */
void	init_stack(t_stack *stack);
t_node	*make_a_node(int content, int *arr4i, int i_amount);
void	put2stack(t_stack *a_s, char *str, unsigned int i_amount, int *arr4i);

/*   stack_utils_2.c    */
void	push_front(t_stack *stack, t_node *new_top);
void	push_back(t_stack *stack, t_node *new_back);
t_node	*pop_front(t_stack *stack);
t_node	*pop_back(t_stack *stack);

/*   stack_orders.c   */
void	do_pstack(t_stack *from, t_stack *to, char name_of_to);
void	do_rstack(t_stack *stack, char name_of_stack);
void	do_rrstack(t_stack *stack, char name_of_stack);
void	do_sstack(t_stack *stack, char name_of_stack);

/*   sort_stacks.c    */
void	sort_a_stack(t_stack *a_stack, t_stack *b_stack, int min, int max);
void	sort_b_stack(t_stack *a_stack, t_stack *b_stack, int min, int max);
void	sort_stacks(t_stack *a_stack, t_stack *b_stack);

/*   sort_stacks_find.c    */
int		find_middle_top(t_node *curr, int middle);
int		find_middle_bottom(t_node *curr, int middle);
int		find_middle_t_min(t_node *curr, int middle, int min);
int		find_middle_b_min(t_node *curr, int middle, int min);
int		find_middle_a_stack(t_node *curr, int middle, int max);

/*   sort_stacks_get.c    */
void	get_m_top(t_stack *a_stack, t_stack *b_stack, int *middle, int max);
void	get_m_bottom(t_stack *a_stack, t_stack *b_stack, int *middle, int max);
int		get_from_astack(t_stack *a_stack, t_stack *b_stack, \
		int *middle, int max);

/*   sort_small.c    */
void	sort_4and5(t_stack *a_stack, t_stack *b_stack);
void	sort_under_3(t_stack *a_stack, t_stack *sort_b_stack, int count);
void	sort_3(t_stack *a_stack);

/*   sort_small_utils.c    */
void	find_min_max(t_stack *a_stack, int *min, int *max);
int		find_4or5_top(t_stack *a_stack, t_node *curr, int middle);
void	pick_4and5(t_stack *a_stack, t_stack *b_stack);

/*   sort_revers.c    */
void	sort_a_stack_r(t_stack *a_stack, t_stack *b_stack, int min, int max);
void	sort_b_stack_r(t_stack *a_stack, t_stack *b_stack, int min, int max);
void	depart_2_big_part_r(t_stack *a_stack, t_stack *b_stack, \
			int min, int quarter);

/*   sort_revers_utils.c    */
int		get_middle_from_ends_r(t_stack *a_stack, t_stack *b_stack, int *middle);
int		get_from_bstack_r(t_stack *a_stack, t_stack *b_stack, \
			int *middle, int max);
void	get_m_top_r(t_stack *a_stack, t_stack *b_stack, int *middle, int max);
void	get_m_bottom_r(t_stack *a_stack, t_stack *b_stack, \
			int *middle, int max);

/*   sort_revers_find.c    */
int		find_middle_a_stack_r(t_node *curr, int middle, int max);

/*   sort_big.c    */
void	sort_stacks_big(t_stack *a_stack, t_stack *b_stack);

/*   sort_big_utils_1.c    */
void	depart_2_big_part(t_stack *a_stack, t_stack *b_stack, \
			int min, int quarter);
void	sort_big_chunk_r(t_stack *a_stack, t_stack *b_stack, \
			int min, int amount_c);
void	sort_big_chunk(t_stack *a_stack, t_stack *b_stack, \
			int min, int amount_c);

/*   sort_big_utils_2.c    */
void	move_second_chunk(t_stack *a, t_stack *b, int amount_c);
void	depart_3_chunk(t_stack *a, t_stack *b, int amount_c, int count_t);
void	depart_third_chunk(t_stack *a, t_stack *b, int amount_c);
void	depart_forth_chunk(t_stack *a, t_stack *b, int amount_c);

/*   sort_big_last.c    */
void	sort_big_last(t_stack *a_stack, t_stack *b_stack, \
			int min, int amount_c);

/*   get_middle.c    */
int		get_middle_from_ends(t_stack *a_stack, t_stack *b_stack, int *middle);

/*   check_sorted.c    */
int		check_sorted(t_stack a_stack);
int		check_parted_sorted(t_stack a_stack);
int		check_parted_sorted_r(t_stack b_stack);

#endif