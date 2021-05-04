/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_list.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 19:28:45 by rkieboom      #+#    #+#                 */
/*   Updated: 2021/04/21 14:47:51 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stack_list/stack_list.h"

#include <stdio.h>

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
