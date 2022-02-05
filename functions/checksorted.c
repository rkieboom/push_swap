/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checksorted.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 19:10:02 by rkieboom      #+#    #+#                 */
/*   Updated: 2022/02/05 12:34:01 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../stack_list/stack_list.h"
#include <unistd.h>

static void	ok(void)
{
	write(1, "OK\n", 3);
	exit(EXIT_SUCCESS);
}

static void	ko(void)
{
	write(1, "KO\n", 3);
	exit(EXIT_SUCCESS);
}

void	checkifsorted(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		num;

	if (!*stack_a || *stack_b)
		ko();
	temp = (*stack_a)->next;
	num = (*stack_a)->value;
	while (temp)
	{
		if (num > temp->value)
			ko();
		num = temp->value;
		temp = temp->next;
	}
	ok();
}

void	checkifsorted_n(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		num;

	if (!*stack_a || *stack_b)
		return ;
	temp = (*stack_a)->next;
	num = (*stack_a)->value;
	while (temp)
	{
		if (num > temp->value)
			return ;
		num = temp->value;
		temp = temp->next;
	}
	exit(0);
}
