/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_swap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/22 21:45:19 by rkieboom      #+#    #+#                 */
/*   Updated: 2021/04/06 00:53:12 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "stack_list/stack_list.h"

void	ft_swap(int *num1, int *num2)
{
	int temp;

	temp = *num2;
	*num2 = *num1;
	*num1 = temp;
}

//Misschien weghalen
void	ft_swapp(struct s_stack *p1, struct s_stack *p2)
{
	struct s_stack temp;
	
	temp = *p2;
	*p2 = *p1;
	*p1 = temp;
}
