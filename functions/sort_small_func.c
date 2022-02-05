/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_small_func.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/05 11:58:15 by rkieboom      #+#    #+#                 */
/*   Updated: 2022/02/05 11:58:54 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../stack_list/stack_list.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*temp;
	int		num;

	temp = stack->next;
	num = stack->value;
	while (temp)
	{
		if (num > temp->value)
			return (0);
		num = temp->value;
		temp = temp->next;
	}
	return (1);
}

int	is_sorted_r(t_stack *stack)
{
	t_stack	*temp;
	int		num;

	temp = stack->next;
	num = stack->value;
	while (temp)
	{
		if (num < temp->value)
			return (0);
		num = temp->value;
		temp = temp->next;
	}
	return (1);
}
