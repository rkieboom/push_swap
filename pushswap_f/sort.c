/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/20 10:52:06 by rkieboom      #+#    #+#                 */
/*   Updated: 2021/05/05 17:11:55 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	checkclosest(t_stack *temp, int num, int buf, int length)
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

int	move_b(t_stack **stack_a, t_stack **stack_b, int buf, int length)
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
			rra(stack_a);
			length--;
		}
		pb(stack_a, stack_b);
	}
	else
	{
		while (closest)
		{
			ra(stack_a);
			closest--;
		}
		pb(stack_a, stack_b);
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

int	move_a(t_stack **stack_a, t_stack **stack_b, int length)
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
			rrb(stack_b);
			length--;
		}
		pa(stack_a, stack_b);
	}
	else
	{
		while (closest)
		{
			rb(stack_b);
			closest--;
		}
		pa(stack_a, stack_b);
	}
	return (1);
}

int	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	buf;

	buf = 30;
	checkifsorted_n(stack_a, stack_b);
	while (*stack_a)
		move_b(stack_a, stack_b, buf, stack_lstsize(*stack_a));
	while (*stack_b)
		move_a(stack_a, stack_b, stack_lstsize(*stack_b));
	checkifsorted(stack_a, stack_b);
	return (1);
}
