# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rkieboom <rkieboom@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/12 19:17:36 by rkieboom      #+#    #+#                  #
#    Updated: 2022/01/25 18:19:53 by rkieboom      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = $(PUSHSWAP) $(CHECKER)

PUSHSWAP = push_swap

CHECKER = checker

LIBFT = libft/libft.a

FLAGS = -Wall -Werror -Wextra

SRCS_CHECKER = $(SRCS.CHECKER) $(SRCS.GNL) $(SRCS.STACK) $(SRCS.COMMANDS) $(SRCS.FUNCTIONS)

SRCS_PUSHSWAP = $(SRCS.PUSHSWAP) $(SRCS.GNL) $(SRCS.STACK) $(SRCS.COMMANDS) $(SRCS.FUNCTIONS)

SRCS.CHECKER = checker_f/checker.c checker_f/input.c

SRCS.PUSHSWAP = pushswap_f/pushswap.c pushswap_f/set_min.c pushswap_f/sort.c pushswap_f/sort3num.c pushswap_f/sort_small.c

SRCS.FUNCTIONS = functions/ft_error.c functions/save_stack.c functions/checksorted.c

SRCS.GNL = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

SRCS.STACK = stack_list/stack_lst_add_front.c stack_list/stack_lst_goto.c stack_list/stack_lst_new.c stack_list/stack_lst_remove.c \
stack_list/stack_lst_add_back.c stack_list/stack_lstlast.c stack_list/stack_lstsize.c

SRCS.COMMANDS = commands/fix_ranking.c commands/ft_swap.c commands/pa_pb.c commands/ra_rb.c commands/rra_rrb.c commands/sa_sb.c commands/get_last_rank.c

O.SRCS_CHECKER = $(SRCS_CHECKER:.c=.o)

O.SRCS_PUSHSWAP = $(SRCS_PUSHSWAP:.c=.o)

all: $(NAME)

$(CHECKER): $(O.SRCS_CHECKER) $(LIBFT)
	$(CC) -g $(FLAGS) $(O.SRCS_CHECKER) $(LIBFT) -o $(CHECKER)

$(PUSHSWAP): $(O.SRCS_PUSHSWAP) $(LIBFT)
	$(CC) -g $(FLAGS) $(O.SRCS_PUSHSWAP) $(LIBFT) -o $(PUSHSWAP)

$(LIBFT):
	make -C Libft/.

%.o: %.c
	$(CC) -g -Wall -Werror -Wextra -Ilibft -c $< -o $@

clean:
	rm -rf $(O.SRCS_CHECKER)
	rm -rf $(O.SRCS_PUSHSWAP)
	make -C Libft/. clean

fclean:
	rm -rf $(NAME)
	rm -rf $(LIBFT)
	rm -rf $(O.SRCS_CHECKER)
	rm -rf $(O.SRCS_PUSHSWAP)
	make -C Libft/. clean

re: fclean all