/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_list.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: spelle <spelle@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/09 14:55:27 by spelle        #+#    #+#                 */
/*   Updated: 2021/04/08 23:50:27 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_LIST_H
# define STACK_LIST_H

# include <stdlib.h>

typedef struct s_stack
{
	int				rank;
	int				value;
	struct s_stack	*next;
}					t_stack;

t_stack	*stack_lst_new(int rank, int value);

void	stack_lst_add_front(t_stack **stack_a, t_stack **stack_b);
void	stack_lst_add_back(t_stack **lst, t_stack *new);
void	stack_lst_remove(t_stack **head, int rank);
t_stack	*stack_lstlast(t_stack *lst);
int		stack_lstsize(t_stack *lst);
t_stack	*stack_lst_goto(t_stack **lst, int rank);

#endif