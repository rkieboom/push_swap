/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_lstlast.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: spelle <spelle@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/09 14:52:36 by spelle        #+#    #+#                 */
/*   Updated: 2021/03/20 16:20:08 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stack_list.h"

t_stack	*stack_lstlast(t_stack *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}
