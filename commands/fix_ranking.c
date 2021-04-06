/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fix_ranking.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 01:18:35 by rkieboom      #+#    #+#                 */
/*   Updated: 2021/04/06 19:30:52 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

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