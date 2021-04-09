/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushswap.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/08 23:54:47 by rkieboom      #+#    #+#                 */
/*   Updated: 2021/04/09 00:13:22 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_F

# include "../commands/commands.h"
# include "../libft/libft.h"
# include "../stack_list/stack_list.h"
# include "../get_next_line/get_next_line.h"

t_stack	*save_stack(char **argv, t_stack *list);
void	ft_reterror(void);

#endif
