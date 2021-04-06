/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/20 16:00:19 by rkieboom      #+#    #+#                 */
/*   Updated: 2021/04/06 19:39:16 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_reterror(void)
{
	write(1, "Error\n", 7);
	exit(EXIT_FAILURE);
}

void	check_args(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ')
			ft_reterror();
		i++;
	}
}

t_stack	*save_args(char **argv, t_stack *list)
{
	int i;

	i = 1;
	while (argv[i])
	{
		check_args(argv[i]);
		if (stack_lstsize(list) == 0)
			list = stack_lst_new(0, ft_atoi(argv[i]));
		else
			stack_lst_add_back(&list, stack_lst_new(stack_lstsize(list), ft_atoi(argv[i])));
		i++;
	}
	return (list);
}

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	(void)argc;
	stack_a = save_args(argv, NULL);
	stack_b = NULL;
	if (!stack_a)
		return (-1);
	if (input(&stack_a, &stack_b) == -1)
		ft_reterror();
	result(&stack_a, &stack_b);
	return (0);
}
