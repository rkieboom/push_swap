/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort2.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/20 10:52:06 by rkieboom      #+#    #+#                 */
/*   Updated: 2021/04/20 14:09:02 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
			if (temp->rank < (length / 2) && temp->rank < result)
				result = temp->rank;
			else if (length - temp->rank < result)
				result = temp->rank;
		}
		temp = temp->next;
	}
	return (result);
}

void	move_b(int num, t_stack **stack_a, t_stack **stack_b)
{
	int length;
	int closest;

	length = stack_lstsize(*stack_a);
	closest = checkclosest(stack_a, num, 30, length);
	if ((length / 2) < closest)
	{
		//beneden
		length = closest;
		while (length)
		{
			rra_rrb(stack_a);
			length--;
		}
		pb(stack_a, stack_b);
	}
	else
	{
		//omhoog
		length = get_last_rank(*stack_a) - length;
		while (length)
		{
			ra_rb(stack_a);
			length--;
		}
		pb(stack_a, stack_b);
	}
	printf("closest = [%i]\n", closest);
}

int	sort2(t_stack **stack_a, t_stack **stack_b)
{
	int	min_max[4];

	set_min_max(min_max, *stack_a, *stack_b);
	move_b(min_max[0] + 15, stack_a, stack_b);
	return (1);
}
