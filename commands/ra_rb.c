/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ra_rb.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 04:02:23 by rkieboom      #+#    #+#                 */
/*   Updated: 2021/04/25 20:14:08 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void	ra(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (!*stack || stack_lstsize(*stack) < 2)
		return ;
	temp = *stack;
	*stack = temp->next;
	temp2 = stack_lstlast(*stack);
	temp2->next = temp;
	temp->next = NULL;
	fix_ranking(stack);
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (!*stack || stack_lstsize(*stack) < 2)
		return ;
	temp = *stack;
	*stack = temp->next;
	temp2 = stack_lstlast(*stack);
	temp2->next = temp;
	temp->next = NULL;
	fix_ranking(stack);
	write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	write(1, "rr\n", 3);
}
