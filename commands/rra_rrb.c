/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rra_rrb.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 04:30:54 by rkieboom      #+#    #+#                 */
/*   Updated: 2021/04/25 20:15:07 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void	rra(t_stack **stack)
{
	t_stack	*temp;

	if (!*stack || stack_lstsize(*stack) < 2)
		return ;
	temp = *stack;
	temp = stack_lstlast(*stack);
	temp->next = *stack;
	*stack = temp;
	temp = stack_lst_goto(stack, (temp->rank - 1));
	temp->next = NULL;
	fix_ranking(stack);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack)
{
	t_stack	*temp;

	if (!*stack || stack_lstsize(*stack) < 2)
		return ;
	temp = *stack;
	temp = stack_lstlast(*stack);
	temp->next = *stack;
	*stack = temp;
	temp = stack_lst_goto(stack, (temp->rank - 1));
	temp->next = NULL;
	fix_ranking(stack);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	write(1, "rrr\n", 4);
}
