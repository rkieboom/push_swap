/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rra_rrb.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 04:30:54 by rkieboom      #+#    #+#                 */
/*   Updated: 2021/04/06 04:48:58 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra_rrb(t_stack **stack)
{
	t_stack *temp;

	if (!*stack || stack_lstsize(*stack) < 2)
		return ;
	temp = *stack;
	temp = stack_lstlast(*stack);
	temp->next = *stack;
	*stack = temp;
	temp = stack_lst_goto(stack, (temp->rank - 1));
	temp->next = NULL;
	fix_ranking(stack);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra_rrb(stack_a);
	rra_rrb(stack_b);
}