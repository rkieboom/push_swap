/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/20 16:00:19 by rkieboom      #+#    #+#                 */
/*   Updated: 2021/04/09 00:08:02 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	(void)argc;
	stack_a = save_stack(argv, NULL);
	stack_b = NULL;
	if (!stack_a)
		return (-1);
	if (input(&stack_a, &stack_b) == -1)
		ft_reterror();
	result(&stack_a, &stack_b);
	return (0);
}
