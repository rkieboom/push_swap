/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_stack.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/09 00:03:50 by rkieboom      #+#    #+#                 */
/*   Updated: 2022/02/05 12:59:49 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap_f/pushswap.h"

static void	check_minus_plus(char *str)
{
	if (str[0] == '-' && ft_isdigit(str[1]) == 0)
		ft_reterror();
	if (str[0] == '+' && ft_isdigit(str[1]) == 0)
		ft_reterror();
}

void	check_args(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			check_minus_plus(str + i);
		if (!ft_isdigit(str[i]) && str[i] != ' ' \
		&& str[i] != '-' && str[i] != '+')
			ft_reterror();
		i++;
	}
}

t_stack	*save_stack(char **argv, t_stack *list, int i, int j)
{
	char	**string;

	while (argv[i])
	{
		check_args(argv[i]);
		string = ft_split(argv[i], ' ');
		if (!string)
			ft_reterror();
		while (string[j])
		{
			if (ft_atoi(string[j]) != ft_atoi_l(string[j]))
				ft_reterror();
			if (stack_lstsize(list) == 0)
				list = stack_lst_new(0, ft_atoi(string[j]));
			else
				stack_lst_add_back(&list, stack_lst_new(stack_lstsize(list), \
				ft_atoi(string[j])));
			free(string[j]);
			j++;
		}
		free(string);
		i++;
		j = 0;
	}
	return (list);
}
