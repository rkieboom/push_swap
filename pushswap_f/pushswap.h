/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushswap.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/08 23:54:47 by rkieboom      #+#    #+#                 */
/*   Updated: 2021/04/20 11:32:05 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../commands/commands.h"
# include "../libft/libft.h"
# include "../stack_list/stack_list.h"
# include "../get_next_line/get_next_line.h"

int		sort(t_stack **stack_a, t_stack **stack_b);
int	sort2(t_stack **stack_a, t_stack **stack_b);

t_stack	*save_stack(char **argv, t_stack *list);
void	set_min_max(int *min_max, t_stack *stack_a, t_stack *stack_b);
void	ft_reterror(void);

#endif
