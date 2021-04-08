/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_lst_add_front.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: spelle <spelle@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/09 15:00:22 by spelle        #+#    #+#                 */
/*   Updated: 2021/04/08 23:51:08 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stack_list.h"

void	stack_lst_add_front(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*temp;

	a = *stack_a;
	b = *stack_b;
	temp = b->next;
	b->next = a;
	*stack_a = b;
	*stack_b = temp;
}
