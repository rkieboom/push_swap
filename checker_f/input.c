/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 18:48:52 by rkieboom      #+#    #+#                 */
/*   Updated: 2021/04/25 20:12:27 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_command(t_stack **stack_a, t_stack **stack_b, char *buf)
{
	if (ft_strncmp("sa", buf, 3) == 0)
		sa(stack_a);
	else if (ft_strncmp("sb", buf, 3) == 0)
		sb(stack_b);
	else if (ft_strncmp("ss", buf, 3) == 0)
		ss(stack_a, stack_b);
	else if (ft_strncmp("pa", buf, 3) == 0)
		pa(stack_a, stack_b);
	else if (ft_strncmp("pb", buf, 3) == 0)
		pa(stack_b, stack_a);
	else if (ft_strncmp("ra", buf, 3) == 0)
		ra(stack_a);
	else if (ft_strncmp("rb", buf, 3) == 0)
		rb(stack_b);
	else if (ft_strncmp("rr", buf, 3) == 0)
		rr(stack_a, stack_b);
	else if (ft_strncmp("rra", buf, 4) == 0)
		rra(stack_a);
	else if (ft_strncmp("rrb", buf, 4) == 0)
		rrb(stack_b);
	else if (ft_strncmp("rrr", buf, 4) == 0)
		rrr(stack_a, stack_b);
}

int	input(t_stack **stack_a, t_stack **stack_b)
{
	int		ret;
	char	*buf;

	ret = 1;
	buf = NULL;
	while (ret == 1)
	{	
		ret = get_next_line(0, &buf);
		if (!buf)
			return (-1);
		check_command(stack_a, stack_b, buf);
		free(buf);
	}
	return (1);
}
