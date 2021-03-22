/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/20 16:00:19 by rkieboom      #+#    #+#                 */
/*   Updated: 2021/03/22 23:51:49 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "stack_list/stack_list.h"
#include "checker.h"
#include <unistd.h>

#include <stdio.h> //Printf

void	ft_reterror(void)
{
	write(1, "Error\n", 7);
	exit(EXIT_FAILURE);
}

void	print_list(t_stack *list)
{
	while (list->next)
	{
		printf("%d=%d\n", list->rank, list->value);
		list = list->next;
	}
	printf("%d=%d\n", list->rank, list->value);
}

void	check_input(char *str)
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
		check_input(argv[i]);
		if (stack_lstsize(list) == 0)
			list = stack_lst_new(0, ft_atoi(argv[i]));
		else
			stack_lstadd_back(&list, stack_lst_new(stack_lstsize(list), ft_atoi(argv[i])));
		i++;
	}
	return (list);
}

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	(void)argc;
	stack_b = NULL;
	stack_a = save_args(argv, NULL);
	if (!stack_a)
		return (-1);

	print_list(stack_a);
	return (0);
}
