/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ra_rb.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 04:02:23 by rkieboom      #+#    #+#                 */
/*   Updated: 2021/04/06 04:50:19 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra_rb(t_stack **stack)
{
	t_stack *temp;
	t_stack *temp2;

	if (!*stack || stack_lstsize(*stack) < 2)
		return ;
	temp = *stack;
	*stack = temp->next;
	temp2 = stack_lstlast(*stack);
	temp2->next = temp;
	temp->next = NULL;
	fix_ranking(stack);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra_rb(stack_a);
	ra_rb(stack_b);
}