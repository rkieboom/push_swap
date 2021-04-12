/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_min_max.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/11 23:36:32 by rkieboom      #+#    #+#                 */
/*   Updated: 2021/04/11 23:45:17 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	set_a(int *min_max, t_stack *stack_a, int min, int max)
{
	while (stack_a)
	{
		if (stack_a->value < min)
			min = stack_a->value;
		if (stack_a->value > max)
			max = stack_a->value;
		stack_a = stack_a->next;
	}
	min_max[0] = min;
	min_max[1] = max;
}

static void	set_b(int *min_max, t_stack *stack_b, int min, int max)
{
	while (stack_b)
	{
		if (stack_b->value < min)
			min = stack_b->value;
		if (stack_b->value > max)
			max = stack_b->value;
		stack_b = stack_b->next;
	}
	min_max[2] = min;
	min_max[3] = max;
}

void	set_min_max(int *min_max, t_stack *stack_a, t_stack *stack_b)
{
	ft_bzero(min_max, sizeof(min_max));
	if (stack_a)
		set_a(min_max, stack_a, stack_a->value, stack_a->value);
	if (stack_b)
		set_b(min_max, stack_b, stack_b->value, stack_b->value);
}
