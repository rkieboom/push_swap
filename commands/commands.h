/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   commands.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 19:26:08 by rkieboom      #+#    #+#                 */
/*   Updated: 2022/02/05 12:15:37 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# include "../stack_list/stack_list.h"
# include <unistd.h>

void	ft_swap(int *num1, int *num2);

void	sa(t_stack **stack_head, int print);
void	sb(t_stack **stack_head, int print);
void	ss(t_stack **stack_a, t_stack **stack_b, int print);

void	pa(t_stack **a, t_stack **b, int print);
void	pb(t_stack **a, t_stack **b, int print);

void	ra(t_stack **stack, int print);
void	rb(t_stack **stack, int print);
void	rr(t_stack **stack_a, t_stack **stack_b, int print);

void	rra(t_stack **stack, int print);
void	rrb(t_stack **stack, int print);
void	rrr(t_stack **stack_a, t_stack **stack_b, int print);

void	fix_ranking(t_stack **head);
int		get_last_rank(t_stack *stack);

#endif