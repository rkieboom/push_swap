/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/22 21:48:26 by rkieboom      #+#    #+#                 */
/*   Updated: 2022/02/05 10:34:21 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>

# include "../stack_list/stack_list.h"
# include "../commands/commands.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

int		input(t_stack **stack_a, t_stack **stack_b);
t_stack	*save_stack(char **argv, t_stack *list, int i, int j);
void	checkifsorted(t_stack **stack_a, t_stack **stack_b);
void	check_duplicate(t_stack **stack_a);
void	ft_reterror(void);

#endif