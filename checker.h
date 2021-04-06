/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/22 21:48:26 by rkieboom      #+#    #+#                 */
/*   Updated: 2021/04/06 04:31:55 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "stack_list/stack_list.h"
# include "libft/libft.h"

void	ft_swap(int *num1, int *num2);
void	ft_swapp(struct s_stack *p1, struct s_stack *p2);

void	sa_sb_ss(char *str, t_stack **stack_a, t_stack **stack_b);

void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

void	ra_rb(t_stack **stack);
void	rr(t_stack **stack_a, t_stack **stack_b);

void	rra_rrb(t_stack **stack);

void	fix_ranking(t_stack **head);

#endif