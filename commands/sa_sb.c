/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sa_sb.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 00:52:32 by rkieboom      #+#    #+#                 */
/*   Updated: 2022/02/05 12:17:22 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void	sa(t_stack **stack_head, int print)
{
	t_stack	*stack;
	t_stack	*new_stack;

	stack = *stack_head;
	if (!stack || stack_lstsize(stack) < 2)
		return ;
	new_stack = stack->next;
	ft_swap(&stack->rank, &new_stack->rank);
	stack->next = new_stack->next;
	new_stack->next = stack;
	*stack_head = new_stack;
	if (print == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack **stack_head, int print)
{
	t_stack	*stack;
	t_stack	*new_stack;

	stack = *stack_head;
	if (!stack || stack_lstsize(stack) < 2)
		return ;
	new_stack = stack->next;
	ft_swap(&stack->rank, &new_stack->rank);
	stack->next = new_stack->next;
	new_stack->next = stack;
	*stack_head = new_stack;
	if (print == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b, int print)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	if (print == 1)
		write(1, "ss\n", 3);
}
