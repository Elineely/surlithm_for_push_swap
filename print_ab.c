#include "stack_utils.h"

#include <stdio.h>

void	print_ab(t_stack a_stack, t_stack b_stack) //+++++++++++++++++++++++++++++
{
//                                        스택 a,b 확인               
	t_node			*curr1;
	t_node			*curr2;

	curr1 = a_stack.head;
	curr2 = b_stack.head;

	printf("-----a-----\n");
	while (curr1)
	{
		printf("%d, [%d]\n", curr1->content, curr1->index);
		curr1 = curr1->next;
	}
	printf("counts : %d\n", a_stack.count_nums);
	printf("top_index : [%d]\n", a_stack.top_index);
	printf("------------\n");
	printf("----b-------\n");
	while (curr2)
	{
		printf("%d, [%d]\n", curr2->content, curr2->index);
		curr2 = curr2->next;
	}
	printf("counts : %d\n", b_stack.count_nums);
	printf("top_index : [%d]\n", b_stack.top_index);
	return ;
	//                                                              
} //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
