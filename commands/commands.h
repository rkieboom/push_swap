/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   commands.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 19:26:08 by rkieboom      #+#    #+#                 */
/*   Updated: 2021/04/25 20:16:37 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# include "../stack_list/stack_list.h"
# include <unistd.h>

void	ft_swap(int *num1, int *num2);

void	sa(t_stack **stack_head);
void	sb(t_stack **stack_head);
void	ss(t_stack **stack_a, t_stack **stack_b);

void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

void	ra(t_stack **stack);
void	rb(t_stack **stack);
void	rr(t_stack **stack_a, t_stack **stack_b);

void	rra(t_stack **stack);
void	rrb(t_stack **stack);
void	rrr(t_stack **stack_a, t_stack **stack_b);

void	fix_ranking(t_stack **head);
int		get_last_rank(t_stack *stack);

#endif