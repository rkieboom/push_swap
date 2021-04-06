/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_lst_goto.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 04:37:11 by rkieboom      #+#    #+#                 */
/*   Updated: 2021/04/06 04:47:04 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stack_list.h"

t_stack	*stack_lst_goto(t_stack **lst, int rank)
{
	t_stack *temp;

	temp = *lst;
	if (!temp)
		return (NULL);
	while (temp->next)
	{
		if (temp->rank == rank)
			return (temp);
		temp = temp->next;
	}
	if (temp->rank == rank)
		return (temp);
	else
		return (NULL);
}
