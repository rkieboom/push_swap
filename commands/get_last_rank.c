/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_last_rank.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/12 02:25:29 by rkieboom      #+#    #+#                 */
/*   Updated: 2021/04/12 02:26:21 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

int		get_last_rank(t_stack *stack)
{
	while (stack->next)
		stack = stack->next;
	return (stack->rank);
}
