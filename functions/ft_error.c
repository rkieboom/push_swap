/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_error.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rkieboom <rkieboom@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/09 00:06:59 by rkieboom      #+#    #+#                 */
/*   Updated: 2021/04/09 00:07:38 by rkieboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_reterror(void)
{
	write(1, "Error\n", 7);
	exit(EXIT_FAILURE);
}
