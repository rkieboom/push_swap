/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   result.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 19:10:02 by rkieboom      #+#    #+#                 */
/*   Updated: 2021/04/06 19:25:28 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ok(void)
{
	write(1, "OK\n", 3);
	exit(EXIT_FAILURE);
}

void	ko(void)
{
	write(1, "KO\n", 3);
	exit(EXIT_FAILURE);
}

void	result(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;
	int temp_num;

	temp = *stack_a;
	if (*stack_b)
		ko();
	temp_num = temp->value;
	while (temp->next)
	{
		if (temp_num > temp->value)
			ko();
		temp_num = temp->value;
		temp = temp->next;
	}
	if (temp_num > temp->value)
			ko();
		ok();
}
