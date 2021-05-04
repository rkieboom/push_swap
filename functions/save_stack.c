/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_stack.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/09 00:03:50 by rkieboom      #+#    #+#                 */
/*   Updated: 2021/04/21 14:43:34 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../stack_list/stack_list.h"
#include "../libft/libft.h"

void	ft_reterror(void);

void	check_args(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		// if (!ft_isdigit(str[i]) && str[i] != ' ')
		// 	ft_reterror();
		i++;
	}
}

t_stack	*save_stack(char **argv, t_stack *list)
{
	int	i;
	int j;
	char **string;

	i = 1;
	j = 0;
	while (argv[i])
	{
		check_args(argv[i]);
		string = ft_split(argv[i], ' ');
		while (string[j])
		{
			if (stack_lstsize(list) == 0)
				list = stack_lst_new(0, ft_atoi(string[j]));
			else
				stack_lst_add_back(&list, stack_lst_new(stack_lstsize(list), ft_atoi(string[j])));
			free(string[j]);
			j++;
		}
		free(string);
		i++;
		j = 0;
	}
	// print_list(list);
	return (list);
}
