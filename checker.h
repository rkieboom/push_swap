/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/22 21:48:26 by rkieboom      #+#    #+#                 */
/*   Updated: 2021/03/23 00:04:55 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "stack_list/stack_list.h"
# include "libft/libft.h"

void	ft_swap(int *num1, int *num2);
void	ft_swapp(struct s_stack *p1, struct s_stack *p2);

void	sa_sb_ss(char *str, t_stack **stack_a, t_stack **stack_b);

#endif