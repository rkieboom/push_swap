/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_lst_remove.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 00:57:44 by rkieboom      #+#    #+#                 */
/*   Updated: 2021/04/08 23:52:00 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stack_list.h"

void	fix_ranking(t_stack **head);

void	stack_lst_remove(t_stack **head, int rank)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = *head;
	if (rank == 0)
	{
		*head = temp->next;
		free(temp);
	}
	else
	{
		while (rank - 1 != temp->rank)
			temp = temp->next;
		temp2 = temp;
		temp2 = temp2->next;
		temp->next = temp2->next;
		free(temp2);
	}
	fix_ranking(head);
}
