/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_lstsize.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: spelle <spelle@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/09 14:52:07 by spelle        #+#    #+#                 */
/*   Updated: 2021/03/20 16:39:59 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stack_list.h"

int	stack_lstsize(t_stack *lst)
{
	int	i;

	i = 1;
	if (!lst)
		return (0);
	while (lst->next)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
