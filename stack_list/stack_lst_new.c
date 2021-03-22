/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_lst_new.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/20 15:59:10 by rkieboom      #+#    #+#                 */
/*   Updated: 2021/03/20 16:30:07 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stack_list.h"

t_stack	*stack_lst_new(int rank, int value)
{
	t_stack	*list;

	list = malloc(sizeof(t_stack));
	if (!list)
		return (NULL);
	list->rank = rank;
	list->value = value;
	list->next = NULL;
	return (list);
}
