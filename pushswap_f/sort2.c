/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort2.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/20 10:52:06 by rkieboom      #+#    #+#                 */
/*   Updated: 2021/05/02 22:22:57 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_list(t_stack *stack_a, t_stack *stack_b);

int		checkifsorted(t_stack **stack_b)
{
	int temp;
	t_stack *stack;

	stack = *stack_b;
	temp = stack->value;
	while (stack)
	{
		if (stack->value > temp)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int		sort_b(t_stack **stack_b)
{
	while (checkifsorted(stack_b) == 0)
	{
		
	}
}

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

int	move_b(int num, t_stack **stack_a, t_stack **stack_b)
{
	int length;
	int closest;

	length = stack_lstsize(*stack_a);
	closest = checkclosest(stack_a, num, 30, length);
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
	printf("closest = [%i]\n", closest);
	return (1);
}

int	sort2(t_stack **stack_a, t_stack **stack_b)
{
	int	min_max[4];

	print_list(*stack_a, *stack_b);
	
	while (*stack_a)
	{
		set_min_max(min_max, *stack_a, *stack_b);
		while (move_b(min_max[0], stack_a, stack_b));
	}



	print_list(*stack_a, *stack_b);
	return (1);
}
