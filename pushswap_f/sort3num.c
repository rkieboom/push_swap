/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort3num.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 14:40:23 by rkieboom      #+#    #+#                 */
/*   Updated: 2022/02/05 12:19:44 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	s_sort(t_stack **stack, int small, int mid, int big)
{
	t_stack	*temp;

	temp = *stack;
	if (temp->value == small)
	{
		rra(stack, 1);
		sa(stack, 1);
	}
	else if (temp->value == mid)
	{
		temp = temp->next;
		if (temp->value == small)
			sa(stack, 1);
		else
			rra(stack, 1);
	}
	else if (temp->value == big)
	{
		temp = temp->next;
		ra(stack, 1);
		if (temp->value == mid)
			sa(stack, 1);
	}
}

void	three_numbers_sort(t_stack **stack_a)
{
	int	small;
	int	mid;
	int	big;

	small = get_smallest(*stack_a);
	big = get_big(*stack_a);
	mid = get_mid(*stack_a, small, big);
	s_sort(stack_a, small, mid, big);
}

static void	s_sort_r(t_stack **stack, int small, int mid, int big)
{
	t_stack	*temp;

	temp = *stack;
	if (temp->value == small)
	{
		rrb(stack, 1);
		sb(stack, 1);
	}
	else if (temp->value == mid)
	{
		temp = temp->next;
		if (temp->value == small)
			sb(stack, 1);
		else
			rrb(stack, 1);
	}
	else if (temp->value == big)
	{
		temp = temp->next;
		rb(stack, 1);
		if (temp->value == mid)
			sb(stack, 1);
	}
}

void	three_numbers_sort_r(t_stack **stack_b)
{
	int	small;
	int	mid;
	int	big;

	big = get_smallest(*stack_b);
	small = get_big(*stack_b);
	mid = get_mid(*stack_b, small, big);
	s_sort_r(stack_b, small, mid, big);
}
