/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sa.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/22 21:40:28 by rkieboom      #+#    #+#                 */
/*   Updated: 2021/03/22 23:44:42 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa_sb(t_stack **stack_head)
{
	t_stack *stack;
	t_stack *new_stack;

	stack = *stack_head;
	if (stack_lstsize(stack) < 2)
		return ;
	new_stack = stack->next;
	ft_swap(&stack->rank, &new_stack->rank);
	stack->next = new_stack->next;
	new_stack->next = stack;
	*stack_head = new_stack;
}

void	sa_sb_ss(char *str, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strncmp(str, "sa", 3) == 0)
		sa_sb(stack_a);
	else if (ft_strncmp(str, "sb", 3) == 0)
		sa_sb(stack_b);
	else if (ft_strncmp(str, "ss", 3) == 0)
	{
		sa_sb(stack_a);
		sa_sb(stack_b);
	}
}
