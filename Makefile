#______________________________________________________________________________#
############################### Target Names ###################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

# Name
NAME	= ./push_swap
CHECKER	= ./checker

#______________________________________________________________________________#
############################### Compiler #######################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

# Compiler
CC = cc

# Compiler Flags
CFLAGS = -Wall -Wextra -Werror

#______________________________________________________________________________#
############################### Libraries ######################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

# Libft
LIB_DIR		= ./libft
LIBFT		= $(LIB_DIR)/libft.a
LDFLAGS 	= -L $(LIB_DIR) -lft

#______________________________________________________________________________#
############################### Print Variables ################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

# Reset
NC = \033[0m

# Colors
YELLOW = \033[0;33m
GREEN = \033[0;32m
BLUE = \033[0;34m
RED = \033[0;31m
PURPLE = \033[0;35m
CYAN = \033[0;36m
BLACK = \033[0;30
WHITE = \033[0;37m

# Colors
BYELLOW = \033[1;33m
BGREEN = \033[1;32m
BBLUE = \033[1;34m
BRED = \033[1;31m
BPURPLE = \033[1;35m
BCYAN = \033[1;36m
BBLACK = \033[1;30m
BWHITE = \033[1;37m

# One Line Output
OL =\e[1A\r\033[K

#______________________________________________________________________________#
############################### Includes #######################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

INC_DIR = ./inc
INCLUDES += -I $(INC_DIR)
INCLUDES += -I $(LIB_DIR)/inc

#______________________________________________________________________________#
############################### Headers ########################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

HEADER += push_swap.h

vpath %.h $(INC_DIR)

#______________________________________________________________________________#
############################### Path Sources ###################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

SRCS_DIR = ./srcs
DIR_PSW = $(SRCS_DIR)/push_swap
DIR_CHK = $(SRCS_DIR)/checker

#______________________________________________________________________________#
############################### SOURCES ########################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

# push_swap_ft
SRCS += stack_core_1.c
SRCS += stack_core_2.c
SRCS += push_swap_util.c
SRCS += push.c
SRCS += swap.c
SRCS += rotate.c
SRCS += reverse.c
SRCS += get_input.c
SRCS += stack_info.c
SRCS += run.c
SRCS += cost_ft.c
SRCS += cost_op.c
SRCS += stack_adv_op.c
SRCS += sort.c

# checker_ft
CHK_SRCS += checker_util.c

#______________________________________________________________________________#
############################### Attribution ####################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

vpath %.c $(DIR_PSW)
vpath %.c $(DIR_CHK)

#______________________________________________________________________________#
############################### Objects ########################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

OBJS_DIR = ./objs
OBJS = $(patsubst %.c, $(OBJS_DIR)/%.o, $(SRCS))
CHK_OBJS = $(patsubst %.c, $(OBJS_DIR)/%.o, $(CHK_SRCS))

#______________________________________________________________________________#
############################### Counter ########################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

TOTAL	= $(words $(SRCS) $(CHK_SRCS))
COUNT	= 0

#______________________________________________________________________________#
############################### Rules ##########################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

#_____Build_____#
all: $(LIBFT) $(NAME)
	@echo "--▶ $(BGREEN)all\t$(GREEN)done$(NC)"
	@echo "--------------------------------------------------"

# Push_swap
$(NAME): $(OBJS) $(DIR_PSW)/$(NAME).c
	@$(CC) $(CFLAGS) $^ $(LDFLAGS) $(INCLUDES) -o $@
    #-----Output-----#
	@printf "$(OL)$(BCYAN)[%2d/%2d]%3d%%\t$(CYAN)All files compiled$(NC)\n" $(COUNT) $(TOTAL) $(PERCENT)
	@echo "▶$(BGREEN)$(NAME)\t$(GREEN)Executable created$(NC)"

$(OBJS): $(OBJS_DIR)/%.o: %.c | $(LIBFT) $(OBJS_DIR) where
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
    #-----Output-----#
	@if [ $(COUNT) = 0 ]; then echo ""; fi
	@$(eval COUNT=$(shell echo $$(($(COUNT)+1))))
	@$(eval PERCENT:=$(shell echo $$((100*$(COUNT)/$(TOTAL)))))
	@printf "$(OL)$(BCYAN)[%2d/%2d]%3d%%\t$(CYAN)Compiling %s$(NC)\n" $(COUNT) $(TOTAL) $(PERCENT) $<

# Checker
$(CHECKER): $(OBJS) $(CHK_OBJS) $(DIR_CHK)/$(CHECKER).c
	@$(CC) $(CFLAGS) $^ $(LDFLAGS) $(INCLUDES) -o $@
    #-----Output-----#
	@printf "$(OL)$(BCYAN)[%2d/%2d] %3d%%\t$(CYAN)All files compiled$(NC)\n" $(COUNT) $(TOTAL) $(PERCENT)
	@echo "▶$(BGREEN)$(CHECKER)\t$(GREEN)Executable created$(NC)"

$(CHK_OBJS): $(OBJS_DIR)/%.o: %.c | $(LIBFT) $(OBJS_DIR) where
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
    #-----Output-----#
	@if [ $(COUNT) = 0 ]; then echo ""; fi
	@$(eval COUNT=$(shell echo $$(($(COUNT)+1))))
	@$(eval PERCENT:=$(shell echo $$((100*$(COUNT)/$(TOTAL)))))
	@printf "$(OL)$(BCYAN)[%2d/%2d] %3d%%\t\t$(CYAN)Compiling %s\t[%d%%]$(NC)\n" $(COUNT) $(TOTAL) $(PERCENT) $<

# Libraries
$(LIBFT):
	@make --no-print-directory all -C $(LIB_DIR)

# Directories
$(OBJS_DIR):
	@mkdir $@

bonus: all $(CHECKER)

#_____Clean_____#
clean: lclean where_c
	@rm -rf $(OBJS_DIR)
    #-----Output-----#
	@echo "▶ $(BYELLOW)clean $(YELLOW)Object files removed from Push_Swap$(NC)"
	@echo "--▶ $(BYELLOW)clean$(YELLOW) done$(NC)"

# Libraries Clean
lclean:
	@make --no-print-directory clean -C $(LIB_DIR)

fclean: clean
	@rm -f $(LIBFT)
	@rm -f $(NAME)
	@rm -f $(CHECKER)
    #-----Output-----#
	@echo "▶ $(BRED)fclean $(RED)libft.a removed$(NC)"
	@echo "\t$(RED)$(NAME) removed$(NC)"
	@echo "\t$(RED)$(CHECKER) removed$(NC)"
	@echo "--▶ $(BRED)fclean$(RED) done$(NC)"

# Current Make
where_c:
	@echo "$(BBLACK)>push_swap$(NC)"

where:
	@echo "$(BBLACK)>push_swap$(NC)"

re: fclean all

.PHONY: all clean fclean re
