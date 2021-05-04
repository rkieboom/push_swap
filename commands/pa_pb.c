/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pa_pb.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 00:55:08 by rkieboom      #+#    #+#                 */
/*   Updated: 2021/04/25 20:13:28 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*b;

	b = *stack_b;
	if (!*stack_b)
		return ;
	if (!*stack_a)
	{
		*stack_a = stack_lst_new(0, b->value);
		stack_lst_remove(stack_b, 0);
	}
	else
		stack_lst_add_front(stack_a, stack_b);
	fix_ranking(stack_a);
	fix_ranking(stack_b);
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;

	a = *stack_a;
	if (!*stack_a)
		return ;
	if (!*stack_b)
	{
		*stack_b = stack_lst_new(0, a->value);
		stack_lst_remove(stack_a, 0);
	}
	else
		stack_lst_add_front(stack_b, stack_a);
	fix_ranking(stack_a);
	fix_ranking(stack_b);
	write(1, "pb\n", 3);
}
