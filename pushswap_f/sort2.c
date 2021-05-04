/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort2.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/20 10:52:06 by rkieboom      #+#    #+#                 */
/*   Updated: 2021/05/04 16:10:43 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_list(t_stack *stack_a, t_stack *stack_b);

int		checkclosest(t_stack **stack_a, int num, int buf, int length)
{
	int result;
	t_stack *temp;

	temp = *stack_a;
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
		if (temp->value >= num - buf && temp->value <= num + buf)
		{
			if (temp->rank < (length / 2) && temp->rank < result)
				result = temp->rank;
			else if (length - temp->rank < result)
				result = temp->rank;
		}
		temp = temp->next;
	}
	return (result);
}

int	move_b(int num, t_stack **stack_a, t_stack **stack_b, int buf)
{
	int length;
	int closest;

	length = stack_lstsize(*stack_a);
	closest = checkclosest(stack_a, num, buf, length);
	// if (!(*stack_a))
	// 	return (0);
	// if (closest == 0)
	// 	pb(stack_a, stack_b);
	if (closest == -1)
		return (0);
	else if ((length / 2) < closest)
	{
		//beneden
		length =  length - closest;
		while (length)
		{
			rra(stack_a);
			length--;
		}
		pb(stack_a, stack_b);
	}
	else
	{
		//omhoog
		length = closest;
		while (length)
		{
			ra(stack_a);
			length--;
		}
		pb(stack_a, stack_b);
	}
	// printf("2closest = [%i]\n", closest);
	return (1);
}

static int	get_biggest_num(t_stack **stack)
{
	int result[2];
	t_stack *temp;

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
	// printf("result = [%i]", result[0]);
	return (result[0]);
}

int	move_a(t_stack **stack_a, t_stack **stack_b)
{
	int length;
	int closest;

	length = stack_lstsize(*stack_b);
	closest = get_biggest_num(stack_b);
	if (closest == -1)
		return (0);
	else if ((length / 2) < closest)
	{
		//beneden
		length =  length - closest;
		while (length)
		{
			rrb(stack_b);
			length--;
		}
		pa(stack_a, stack_b);
	}
	else
	{
		//omhoog
		length = closest;
		while (length)
		{
			rb(stack_b);
			length--;
		}
		pa(stack_a, stack_b);
	}
	// printf("1closest = [%i]\n", closest);
	return (1);
	
}

int	checkifsorted(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;
	int num;

	if (!*stack_a || *stack_b)
		return (0);
	temp = (*stack_a)->next;
	num = (*stack_a)->value;
	while (temp)
	{
		if (num > temp->value)
			return (0);
		num = temp->value;
		temp = temp->next;
	}
	return (1);
}

int	sort2(t_stack **stack_a, t_stack **stack_b, int buf)
{
	int	min_max[4];

	// print_list(*stack_a, *stack_b);
	
	while (*stack_a)
	{
		set_min_max(min_max, *stack_a, *stack_b);
		while (move_b(min_max[0], stack_a, stack_b, buf));
	}
	while (*stack_b)
	{
		set_min_max(min_max, *stack_a, *stack_b);
		while (move_a(stack_a, stack_b));
	}
	if (checkifsorted(stack_a, stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (1);
}
