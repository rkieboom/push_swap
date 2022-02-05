/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_duplicate.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/03 14:13:37 by rkieboom      #+#    #+#                 */
/*   Updated: 2022/02/05 10:34:58 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap_f/pushswap.h"

void	check_duplicate(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*i;
	int		j;
	int		k;

	k = 0;
	temp = *stack_a;
	while (temp)
	{
		i = *stack_a;
		j = 0;
		while (i)
		{
			if (j != k && temp->value == i->value)
				ft_reterror();
			i = i->next;
			j++;
		}
		temp = temp->next;
		k++;
	}
}
