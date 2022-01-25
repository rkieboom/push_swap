/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_small.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 17:44:10 by rkieboom      #+#    #+#                 */
/*   Updated: 2022/01/25 19:46:39 by rkieboom      ########   odam.nl         */
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


void	sort_small(t_stack **stack_a, t_stack **stack_b, int size)
{
	t_stack *temp;
	int	oldnum;
	int i;
	int j;

	i = 0;
	j = 0;
	temp = *stack_a;
	size = stack_lstsize(temp);
	while (i < (size - 1))//hier mee bezig
	{
		oldnum = temp->value;
		temp = temp->next;
		if (oldnum > temp->value)
			sa(stack_a);
		checkifsorted_n(stack_a, 0);
		ra(stack_a);
		i++;
	}
	print_list(*stack_a, 0);
	
}