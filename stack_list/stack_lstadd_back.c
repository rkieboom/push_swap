/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_lstadd_back.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: spelle <spelle@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/09 14:53:16 by spelle        #+#    #+#                 */
/*   Updated: 2021/03/20 16:24:37 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stack_list.h"

void	stack_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	temp = *lst;
	temp = stack_lstlast(temp);
	temp->next = new;
}
