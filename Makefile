NAME = push_swap
NAMEB = checker
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
M_DIR = Mandatory
B_DIR = Bonus
COMMON_SOURCES =	$(M_DIR)/convert_argv_to_array.c \
					$(M_DIR)/count_and_validate.c \
					$(M_DIR)/create_node.c \
					$(M_DIR)/lst_add_back.c \
					$(M_DIR)/get_last_node.c \
					$(M_DIR)/push_swap_utils.c \
					$(M_DIR)/sorting_algorithm.c \
					$(M_DIR)/tiny_sort.c \
					$(M_DIR)/find_dup.c \
					$(M_DIR)/stack_init.c

SOURCES = $(COMMON_SOURCES) $(M_DIR)/push_swap.c 

SOURCES_BONUS = 	$(COMMON_SOURCES) \
			$(B_DIR)/check_if_sorted_bonus.c \
			$(B_DIR)/get_next_line_bonus.c \
			$(B_DIR)/get_next_line_utils_bonus.c \
			$(B_DIR)/instructions_bonus.c \
			$(B_DIR)/stringcmp_bonus.c \
			$(B_DIR)/checker_bonus.c

OBJS = $(SOURCES:.c=.o)
OBJSB = $(SOURCES_BONUS:.c=.o)

all: $(NAME)
bonus: $(NAMEB)

$(NAME): $(OBJS) $(M_DIR)/push_swap.h
	cc $(CFLAGS) $(OBJS) -o $(NAME)

$(NAMEB): $(OBJSB) $(B_DIR)/checker_bonus.h
	cc $(CFLAGS) $(OBJSB) -o $(NAMEB)

clean:
	@$(RM) $(OBJS) $(OBJSB)

fclean: clean
	@$(RM) $(NAME) $(NAMEB)

re: fclean all bonus

.PHONY: all bonus fclean clean re