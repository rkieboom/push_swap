/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_list.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 19:28:45 by rkieboom      #+#    #+#                 */
/*   Updated: 2021/04/12 00:11:20 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stack_list/stack_list.h"

#include <stdio.h>

void	print_list(t_stack *list)
{
	if (!list)
	{
		printf("NULL\n");
		return ;
	}
	while (list->next)
	{
		printf("%d=%d\n", list->rank, list->value);
		list = list->next;
	}
	printf("%d=%d\n", list->rank, list->value);
}
