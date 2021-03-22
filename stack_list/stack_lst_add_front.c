/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_lst_add_front.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: spelle <spelle@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/09 15:00:22 by spelle        #+#    #+#                 */
/*   Updated: 2021/03/23 00:04:17 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stack_list.h"

void	stack_lst_add_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}
