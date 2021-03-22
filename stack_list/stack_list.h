/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_list.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: spelle <spelle@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/09 14:55:27 by spelle        #+#    #+#                 */
/*   Updated: 2021/03/20 16:30:04 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_LIST_H
# define STACK_LIST_H

#include <stdlib.h>

typedef struct s_stack
{
	int	rank;
	int value;
	struct s_stack	*next;
}				t_stack;

t_stack	*stack_lst_new(int rank, int value);

void	stack_lst_add_front(t_stack **lst, t_stack *new);
void	stack_lstadd_back(t_stack **lst, t_stack *new);
void	stack_lstclear(t_stack **lst, void (*del)(void*));
t_stack	*stack_lstlast(t_stack *lst);
int		stack_lstsize(t_stack *lst);


#endif