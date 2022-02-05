/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_mid_big.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/05 12:02:42 by rkieboom      #+#    #+#                 */
/*   Updated: 2022/02/05 12:04:11 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../stack_list/stack_list.h"

int	get_smallest(t_stack *stack)
{
	int	small;

	small = stack->value;
	while (stack)
	{
		if (stack->value < small)
			small = stack->value;
		stack = stack->next;
	}
	return (small);
}

int	get_mid(t_stack *stack, int small, int big)
{
	int	mid;

	while (stack)
	{
		if (stack->value > small && stack->value < big)
			mid = stack->value;
		stack = stack->next;
	}
	return (mid);
}

int	get_big(t_stack *stack)
{
	int	big;

	big = stack->value;
	while (stack)
	{
		if (stack->value > big)
			big = stack->value;
		stack = stack->next;
	}
	return (big);
}
