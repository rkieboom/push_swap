/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/20 16:00:19 by rkieboom      #+#    #+#                 */
/*   Updated: 2022/02/05 10:34:04 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	if (input(&stack_a, &stack_b) == -1)
		ft_reterror();
	checkifsorted(&stack_a, &stack_b);
	return (0);
}
