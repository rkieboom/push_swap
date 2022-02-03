/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_small.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 17:44:10 by rkieboom      #+#    #+#                 */
/*   Updated: 2022/01/30 19:18:08 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_list(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a)
		printf("List a NULL\n\n");
	else
	{
		printf("List a:\n");
		while (stack_a->next)
		{
			printf("%d=%d\n", stack_a->rank, stack_a->value);
			stack_a = stack_a->next;
		}
		printf("%d=%d\n\n", stack_a->rank, stack_a->value);
	}
	if (!stack_b)
		printf("List b NULL\n");
	else
	{
		printf("List b:\n");
		while (stack_b->next)
		{
			printf("%d=%d\n", stack_b->rank, stack_b->value);
			stack_b = stack_b->next;
		}
		printf("%d=%d\n", stack_b->rank, stack_b->value);
	}
	printf("\n---\n\n");
}

static int somefunc(t_stack **stack, int find)
{
	int result;
	t_stack *temp;

	result = 0;
	temp = *stack;
	while (temp)
	{
		if (temp->value < find)
			result++;
		temp = temp->next;
	}
	return (result);
}

void	sort_small(t_stack **stack_a, t_stack **stack_b, int size)
{					
	t_stack *temp;				
	int oldnum;

	temp = (*stack_a)->next;
	oldnum = (*stack_a)->value;			//   start  		  4 3 6 2
										//   start    swap      rra       rra       swap      rra       rra 
	checkifsorted_n(stack_a, stack_b); // 3 2 6 4 - 2 3 6 4 - 4 2 3 6 - 6 4 2 3 - 4 6 2 3 - 3 4 6 2 - 2 3 4 6
	while (1)
	{
		temp = (*stack_a)->next;
		oldnum = (*stack_a)->value;
		if (oldnum > temp->value && somefunc(stack_a, oldnum))
			sa(stack_a);
		checkifsorted_n(stack_a, stack_b);
		rra(stack_a);
		checkifsorted_n(stack_a, stack_b);
		print_list(*stack_a, *stack_b);
		sleep(3);
	}
	

	size = 0;
}
