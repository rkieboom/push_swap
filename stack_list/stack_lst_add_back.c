/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_lst_add_back.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: spelle <spelle@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/09 14:53:16 by spelle        #+#    #+#                 */
/*   Updated: 2021/04/06 19:38:56 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stack_list.h"

void	stack_lst_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	temp = *lst;
	temp = stack_lstlast(temp);
	temp->next = new;
}
