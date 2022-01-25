/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushswap.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/08 23:54:47 by rkieboom      #+#    #+#                 */
/*   Updated: 2022/01/25 18:18:27 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../commands/commands.h"
# include "../libft/libft.h"
# include "../stack_list/stack_list.h"
# include "../get_next_line/get_next_line.h"

void		sort(t_stack **stack_a, t_stack **stack_b);
void	checkifsorted(t_stack **stack_a, t_stack **stack_b);
int		checkifsorted_n(t_stack **stack_a, t_stack **stack_b);
t_stack	*save_stack(char **argv, t_stack *list);
int		set_min(t_stack *stack);
void	ft_reterror(void);
void	sort_small(t_stack **stack, int size);
void	three_numbers_sort(t_stack **stack_a);

#endif
