/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/20 10:52:06 by rkieboom      #+#    #+#                 */
/*   Updated: 2022/02/05 12:19:21 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	checkclosest(t_stack *temp, int num, int buf, int length)
{
	int		result;

	result = length;
	while (temp)
	{
		if (temp->value >= num - buf && temp->value <= num + buf)
		{
			result = temp->rank;
			break ;
		}
		temp = temp->next;
	}
	if (!temp)
		return (-1);
	while (temp)
	{
		if (temp->value >= num - buf && temp->value <= num + buf && \
		length - temp->rank < result)
			result = temp->rank;
		temp = temp->next;
	}
	return (result);
}

static int	move_b(t_stack **stack_a, t_stack **stack_b, int buf, int length)
{
	int	closest;

	closest = checkclosest(*stack_a, set_min(*stack_a), buf, length);
	if (closest == -1)
		return (0);
	else if ((length / 2) < closest)
	{
		length = length - closest;
		while (length)
		{
			rra(stack_a, 1);
			length--;
		}
		pb(stack_a, stack_b, 1);
	}
	else
	{
		while (closest)
		{
			ra(stack_a, 1);
			closest--;
		}
		pb(stack_a, stack_b, 1);
	}
	return (1);
}

static int	get_biggest_num(t_stack **stack)
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
		if (temp->value > result[1])
		{
			result[0] = temp->rank;
			result[1] = temp->value;
		}
		temp = temp->next;
	}
	return (result[0]);
}

static int	move_a(t_stack **stack_a, t_stack **stack_b, int length)
{
	int	closest;

	closest = get_biggest_num(stack_b);
	if (closest == -1)
		return (0);
	else if ((length / 2) < closest)
	{
		length = length - closest;
		while (length)
		{
			rrb(stack_b, 1);
			length--;
		}
		pa(stack_a, stack_b, 1);
	}
	else
	{
		while (closest)
		{
			rb(stack_b, 1);
			closest--;
		}
		pa(stack_a, stack_b, 1);
	}
	return (1);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	buf;

	size = stack_lstsize(*stack_a);
	if (size >= 1 && size <= 10)
		buf = 1;
	else
		buf = 30;
	checkifsorted_n(stack_a, stack_b);
	if (size == 2)
		sa(stack_a, 1);
	else if (size == 3)
		three_numbers_sort(stack_a);
	else if (size >= 4 && size <= 6)
		sort_small(stack_a, stack_b, stack_lstsize(*stack_a));
	else
	{
		while (*stack_a)
			move_b(stack_a, stack_b, buf, stack_lstsize(*stack_a));
		while (*stack_b)
			move_a(stack_a, stack_b, stack_lstsize(*stack_b));
	}
}
