/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushswap.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/08 23:55:52 by rkieboom      #+#    #+#                 */
/*   Updated: 2021/05/04 15:09:34 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_list(t_stack *stack_a, t_stack *stack_b);

int		main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	if (argc < 2)
		return (0);
	stack_a = save_stack(argv, NULL);
	if (!stack_a)
		return (-1);

	sort2(&stack_a, &stack_b, 30);
	// print_list(stack_a);
	// printf("\n\n\n-----\n\n\n");
	// print_list(stack_b);
	return (0);
}
