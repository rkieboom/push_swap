/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_small.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 17:30:59 by rkieboom      #+#    #+#                 */
/*   Updated: 2022/02/05 12:20:39 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	get_lowest_num(t_stack **stack)
{
	int		result[2];
	t_stack	*temp;

	temp = *stack;
	if (!temp)
		return (-1);
	result[0] = temp->rank;
	result[1] = temp->value;
	while (temp)
	{
		if (temp->value < result[1])
		{
			result[0] = temp->rank;
			result[1] = temp->value;
		}
		temp = temp->next;
	}
	return (result[0]);
}

static void	move_b(t_stack **stack_a, t_stack **stack_b, int push, int size)
{
	if (push < (size / 2))
	{
		while (push)
		{
			ra(stack_a, 1);
			push--;
		}
	}
	else
	{
		if (push >= (size / 2))
		{
			while (get_lowest_num(stack_a) != (*stack_a)->rank)
				rra(stack_a, 1);
		}
	}
	pb(stack_a, stack_b, 1);
}

static int	get_new_size(int size)
{
	if (size == 4)
		return (1);
	else if (size == 5)
		return (2);
	else
		return (3);
}

void	sort_small(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	push;

	size = get_new_size(size);
	while (size)
	{
		push = get_lowest_num(stack_a);
		move_b(stack_a, stack_b, push, stack_lstsize(*stack_a));
		size--;
	}
	if (!is_sorted(*stack_a))
		three_numbers_sort(stack_a);
	if (stack_lstsize(*stack_b) == 3 && !is_sorted_r(*stack_b))
		three_numbers_sort_r(stack_b);
	if (stack_lstsize(*stack_b) == 2)
	{
		if (is_sorted(*stack_b))
			sb(stack_b, 1);
	}
	while (*stack_b)
		pa(stack_a, stack_b, 1);
}
