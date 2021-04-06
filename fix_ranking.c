/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fix_ranking.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 01:18:35 by rkieboom      #+#    #+#                 */
/*   Updated: 2021/04/06 03:54:08 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	fix_ranking(t_stack **head)
{
	t_stack *temp;
	int i;

	if (!*head)
		return ;
	i = 0;
	temp = *head;
	while (temp->next)
	{
		temp->rank = i;
		temp = temp->next;
		i++;
	}
	temp->rank = i;
}