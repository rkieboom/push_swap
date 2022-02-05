# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rkieboom <rkieboom@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/02/03 16:05:06 by rkieboom      #+#    #+#                  #
#    Updated: 2022/02/05 12:01:53 by rkieboom      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# ================================ VARIABLES ================================= #

# The name of your executable
NAME		= push_swap

NAME_BONUS	= checker

# Compiler and compiling flags
CC	= gcc
CFLAGS	= -Wall -Werror -Wextra

# Debug, use with`make DEBUG=1`
ifeq ($(DEBUG),1)
CFLAGS	+= -g3 -fsanitize=address
endif

# Folder name
SRCDIR	= ./
OBJDIR	= bin/
LIBFTDIR = libft/

LIBFTLIB = $(LIBFTDIR)/libft.a

SRCS =	$(SRCS_PUSHSWAP)

SRCS.BONUS = $(SRCS_CHECKER)

SRCS_CHECKER = $(SRCS.CHECKER) $(SRCS.GNL) $(SRCS.STACK) $(SRCS.COMMANDS) $(SRCS.FUNCTIONS)

SRCS_PUSHSWAP = $(SRCS.PUSHSWAP) $(SRCS.STACK) $(SRCS.COMMANDS) $(SRCS.FUNCTIONS)

SRCS.CHECKER = checker_f/checker.c checker_f/input.c

SRCS.PUSHSWAP = pushswap_f/pushswap.c pushswap_f/set_min.c pushswap_f/sort.c pushswap_f/sort3num.c \
				pushswap_f/sort_small.c 

SRCS.FUNCTIONS = functions/ft_error.c functions/save_stack.c functions/checksorted.c functions/check_duplicate.c \
				functions/ft_atoi_l.c functions/sort_small_func.c functions/small_mid_big.c

SRCS.GNL = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

SRCS.STACK = stack_list/stack_lst_add_front.c stack_list/stack_lst_goto.c stack_list/stack_lst_new.c stack_list/stack_lst_remove.c \
stack_list/stack_lst_add_back.c stack_list/stack_lstlast.c stack_list/stack_lstsize.c

SRCS.COMMANDS = commands/fix_ranking.c commands/ft_swap.c commands/pa_pb.c \
				commands/ra_rb.c commands/rra_rrb.c commands/sa_sb.c commands/get_last_rank.c

# String manipulation magic
SRC		:= $(notdir $(SRCS))
OBJ		:= $(SRC:.c=.o)
OBJS	:= $(addprefix $(OBJDIR), $(OBJ))

SRC_B		:= $(notdir $(SRCS.BONUS))
OBJ_B		:= $(SRC_B:.c=.o)
OBJS_B	:= $(addprefix $(OBJDIR), $(OBJ_B))

# Colors
GR	= \033[32;1m
RE	= \033[31;1m
YE	= \033[33;1m
CY	= \033[36;1m
RC	= \033[0m

# Implicit rules
VPATH := $(SRCDIR) $(OBJDIR) $(shell find $(SRCDIR) -type d)

# ================================== RULES =================================== #

all : $(NAME)

# Compiling
$(OBJDIR)%.o : %.c
	@mkdir -p $(OBJDIR)
	@printf "$(GR)+$(RC)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Linking
$(NAME)	: $(LIBFTLIB) $(SRCS)  $(OBJS)
	@printf "\n$(GR)=== Compiled [$(CC) $(CFLAGS)] ===\n--- $(SRC)$(RC)\n"
	@$(CC) $(CFLAGS) $(LIBFTLIB) $(OBJS) -o $(NAME)

$(LIBFTLIB) :
	make -C $(LIBFTDIR)
	
# Cleaning
clean :
	@printf "$(RE)--- Removing $(OBJDIR)$(RC)\n"
	@rm -rf $(OBJDIR)
	@make -C $(LIBFTDIR) clean

fclean : clean
	@printf "$(RE)--- Removing $(NAME) & $(NAME_BONUS)$(RC)\n"
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@make -C $(LIBFTDIR) fclean

# Special rule to force to remake everything
re : fclean all

bonus : all $(SRCS.BONUS) $(OBJS_B)
	@printf "\n$(GR)=== Compiled [$(CC) $(CFLAGS)] ===\n--- $(SRC_B)$(RC)\n"
	@$(CC) $(CFLAGS) $(LIBFTLIB) $(OBJS_B) -o $(NAME_BONUS)

# This runs the program
run : $(NAME)
	@printf "$(CY)>>> Running $(NAME)$(RC)\n"
	./$(NAME)

# This specifies the rules that does not correspond to any filename
.PHONY	= all run clean fclean re bonus