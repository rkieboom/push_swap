/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort3num.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 14:40:23 by rkieboom      #+#    #+#                 */
/*   Updated: 2022/01/25 18:20:27 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int		get_smallest(t_stack *stack)
{
	int small;

	small = stack->value;
	while (stack)
	{
		if (stack->value < small)
			small = stack->value;
		stack = stack->next;
	}
	return (small);
}

static int		get_mid(t_stack *stack, int small, int big)
{
	int mid;
	
	while (stack)
	{
		if (stack->value > small && stack->value < big)
			mid = stack->value;
		stack = stack->next;
	}
	return (mid);
}

static int		get_big(t_stack *stack)
{
	int big;

	big = stack->value;
	while (stack)
	{
		if (stack->value > big)
			big = stack->value;
		stack = stack->next;
	}
	return (big);
}

static void		s_sort(t_stack **stack, int small, int mid, int big)
{
	t_stack *temp;

	temp = *stack;
	if (temp->value == small)
	{
		rra(stack);
		sa(stack);
	}
	else if (temp->value == mid)
	{
		temp = temp->next;
		if (temp->value == small)
			sa(stack);
		else
			rra(stack);
	}
	else if (temp->value == big)
	{
		temp = temp->next;
		ra(stack);
		if (temp->value == mid)
			sa(stack);
	}
}

void			three_numbers_sort(t_stack **stack_a)
{
	int small;
	int mid;
	int big;

	small = get_smallest(*stack_a);
	big = get_big(*stack_a);
	mid = get_mid(*stack_a, small, big);

	s_sort(stack_a, small, mid, big);
}