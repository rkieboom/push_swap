/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushswap.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/08 23:54:47 by rkieboom      #+#    #+#                 */
/*   Updated: 2022/02/05 12:31:08 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../commands/commands.h"
# include "../libft/libft.h"
# include "../stack_list/stack_list.h"
# include "../get_next_line/get_next_line.h"

void		sort(t_stack **stack_a, t_stack **stack_b);
void		sort_small(t_stack **stack_a, t_stack **stack_b, int size);

void		checkifsorted(t_stack **stack_a, t_stack **stack_b);
void		checkifsorted_n(t_stack **stack_a, t_stack **stack_b);
void		check_duplicate(t_stack **stack_a);

t_stack		*save_stack(char **argv, t_stack *list, int i, int j);
long long	ft_atoi_l(const char *str);
int			set_min(t_stack *stack);

int			get_smallest(t_stack *stack);
int			get_mid(t_stack *stack, int small, int big);
int			get_big(t_stack *stack);

void		three_numbers_sort(t_stack **stack_a);
void		three_numbers_sort_r(t_stack **stack);

int			is_sorted(t_stack *stack);
int			is_sorted_r(t_stack *stack);

void		ft_reterror(void);

#endif
