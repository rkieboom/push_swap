/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   commands.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 19:26:08 by rkieboom      #+#    #+#                 */
/*   Updated: 2021/04/12 02:26:29 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# include "../stack_list/stack_list.h"

void	ft_swap(int *num1, int *num2);

void	sa_sb(t_stack **stack_head);
void	ss(t_stack **stack_a, t_stack **stack_b);

void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

void	ra_rb(t_stack **stack);
void	rr(t_stack **stack_a, t_stack **stack_b);

void	rra_rrb(t_stack **stack);
void	rrr(t_stack **stack_a, t_stack **stack_b);

void	fix_ranking(t_stack **head);
int		get_last_rank(t_stack *stack);

#endif