/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checksorted.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 19:10:02 by rkieboom      #+#    #+#                 */
/*   Updated: 2021/05/05 16:42:12 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../stack_list/stack_list.h"
#include <unistd.h>

static void	ok(void)
{
	write(1, "OK\n", 3);
}

static void	ko(void)
{
	write(1, "KO\n", 3);
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

int	checkifsorted_n(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		num;

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
	ok();
	exit(0);
}
