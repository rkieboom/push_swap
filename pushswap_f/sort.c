/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/10 00:57:05 by rkieboom      #+#    #+#                 */
/*   Updated: 2021/04/20 13:22:34 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	move_b(t_stack **stack_a, t_stack **stack_b, int *min_max)
{
	int length;

	length = stack_lstsize(*stack_a);

	set_min_max(min_max, *stack_a, *stack_b);
	while (length - 1)
	{
		if ((*stack_a)->value == min_max[1] && printf("ra\n"))
			ra_rb(stack_a);
		else if (printf("pb\n"))
			pb(stack_a, stack_b);
		length--;
	}
}

void	move_a(t_stack **stack_a, t_stack **stack_b, int *min_max)
{
	t_stack *temp;
	int length;

	while ((*stack_b))
	{
		set_min_max(min_max, *stack_a, *stack_b);
		temp = *stack_b;
		if ((*stack_b)->value == min_max[3] && printf("pa\n"))
			pa(stack_a, stack_b);
		else
		{
			while (temp && temp->value != min_max[3])
				temp = temp->next;
			if (((stack_lstsize(*stack_b) / 2) + 1) < temp->rank)
			{
				//beneden	
				length = get_last_rank(temp) - ((stack_lstsize(*stack_b) / 2) + 1);
				while (length)
				{
					printf("rrb\n");
					rra_rrb(stack_b);
					length--;
				}
			}
			else
			{
				//omhoog
				length = temp->rank;
				while (length)
				{
					printf("rb\n");
					ra_rb(stack_b);
					length--;
				}
			}
		}
	}
}

int		sort(t_stack **stack_a, t_stack **stack_b)
{
	int min_max[4];
	move_b(stack_a, stack_b, min_max);
	move_a(stack_a, stack_b, min_max);
	return (0);	
}
