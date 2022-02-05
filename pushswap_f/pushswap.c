/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushswap.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/08 23:55:52 by rkieboom      #+#    #+#                 */
/*   Updated: 2022/02/05 10:33:24 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	if (argc < 2)
		return (0);
	stack_a = save_stack(argv, NULL, 1, 0);
	if (!stack_a)
		return (-1);
	check_duplicate(&stack_a);
	sort(&stack_a, &stack_b);
	return (0);
}
