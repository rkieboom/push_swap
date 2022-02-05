/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ra_rb.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 04:02:23 by rkieboom      #+#    #+#                 */
/*   Updated: 2022/02/05 12:17:37 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void	ra(t_stack **stack, int print)
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
	if (print == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack **stack, int print)
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
	if (print == 1)
		write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b, int print)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (print == 1)
		write(1, "rr\n", 3);
}
