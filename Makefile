# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rkieboom <rkieboom@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/12 19:17:36 by rkieboom      #+#    #+#                  #
#    Updated: 2021/04/06 04:45:00 by rkieboom      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = checker

LIBFT = libft/libft.a

FLAGS = -Wall -Werror -Wextra

SRCS = stack_list/stack_lst_new.c stack_list/stack_lstlast.c stack_list/stack_lstsize.c stack_list/stack_lstadd_back.c \
checker.c ft_swap.c sa_sb.c pa_pb.c stack_list/stack_lst_remove.c stack_list/stack_lst_add_front.c \
fix_ranking.c ra_rb.c rra_rrb.c stack_list/stack_lst_goto.c

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