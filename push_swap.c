/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: surlee <surlee@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 18:57:46 by surlee            #+#    #+#             */
/*   Updated: 2022/06/07 09:10:45 by surlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack_utils.h"

static void	print_orders(int input_amount, t_stack *a_stack, t_stack *b_stack)
{
	if (input_amount > 100)
		sort_stacks_big(a_stack, b_stack);
	else if (input_amount > 5)
		sort_stacks(a_stack, b_stack);
	else if (input_amount > 3)
		sort_4and5(a_stack, b_stack);
	else
		sort_under_3(a_stack, b_stack, input_amount);
}

int	main(int argc, char **argv)
{
	int				i;
	unsigned int	input_amount;
	int				*arr4i;
	t_stack			a_stack;
	t_stack			b_stack;

	input_amount = check_input(argc, argv);
	if (input_amount == 1)
		exit(0);
	init_stack(&a_stack);
	init_stack(&b_stack);
	arr4i = malloc(sizeof(int) * (input_amount));
	if (arr4i == NULL)
		exit(1);
	arr4i = index_input(argc, argv, input_amount, arr4i);
	i = 1;
	while (i < argc)
		put2stack(&a_stack, argv[i++], input_amount, arr4i);
	free(arr4i);
	if (check_sorted(a_stack))
		exit (0);
	print_orders(input_amount, &a_stack, &b_stack);
	return (1);
}
