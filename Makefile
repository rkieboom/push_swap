# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rkieboom <rkieboom@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/12 19:17:36 by rkieboom      #+#    #+#                  #
#    Updated: 2021/04/06 19:42:09 by rkieboom      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = checker

LIBFT = libft/libft.a

FLAGS = -Wall -Werror -Wextra

SRCS = $(SRCS.CHECKER) $(SRCS.GNL) $(SRCS.STACK) $(SRCS.COMMANDS)

SRCS.CHECKER = checker_f/checker.c checker_f/input.c checker_f/result.c

SRCS.PUSHSWAP = 

SRCS.GNL = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

SRCS.STACK = stack_list/stack_lst_add_front.c stack_list/stack_lst_goto.c stack_list/stack_lst_new.c stack_list/stack_lst_remove.c \
stack_list/stack_lst_add_back.c stack_list/stack_lstlast.c stack_list/stack_lstsize.c

SRCS.COMMANDS = commands/fix_ranking.c commands/ft_swap.c commands/pa_pb.c commands/ra_rb.c commands/rra_rrb.c commands/sa_sb.c

O.SRCS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(O.SRCS) $(LIBFT)
	$(CC) $(FLAGS) $(O.SRCS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C Libft/.

%.o: %.c
	$(CC) -Wall -Werror -Wextra -Ilibft -c $< -o $@

clean:
	rm -rf $(O.SRCS)
	make -C Libft/. clean

fclean:
	rm -rf $(NAME)
	rm -rf $(LIBFT)
	rm -rf $(O.SRCS)
	make -C Libft/. clean

re: fclean all