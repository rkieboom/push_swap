/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_swap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/22 21:45:19 by rkieboom      #+#    #+#                 */
/*   Updated: 2021/04/06 19:31:01 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void	ft_swap(int *num1, int *num2)
{
	int	temp;

	temp = *num2;
	*num2 = *num1;
	*num1 = temp;
}
