#Compiler and Linker
CC          = gcc

#Target .exe
TARGET		= push_swap
CHECKER		= checker

#Directories, Source, Objects, Lib
SRCS_DIR		= srcs/
BNS_SRCS_DIR	= srcs_bns/
MAIN_DIR		= main/
OBJS_DIR		= objs/
LIB_DIR			= libft/

#Flags, Libraries and Includes
INCLUDES	= -I ./inc/
CFLAGS		= -Wall -Werror -Wextra
LIBFT		= $(LIB_DIR)libft.a
LDFLAGS 	= -L $(LIB_DIR) -lft

#Colors
RESET		= \033[0;39m
GRAY		= \033[0;90m
RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[0;93m
BLUE		= \033[0;34m
PURPLE		= \033[1;35m
CYAN		= \033[0;96m
WHITE		= \033[0;97m

# Inverted, i.e. colored backgrounds
IGREY		= \033[40m
IRED		= \033[41m
IGREEN		= \033[42m
IYELLOW		= \033[43m
IBLUE		= \033[44m
IPURPLE		= \033[45m
ICYAN		= \033[46m
IWHITE		= \033[47m

#Counter
COUNT		= 0
COUNT_BONUS	= 0

#---------------------------------------------------------------------------------
#Do not edit below this line
#---------------------------------------------------------------------------------

#---------------------------------------------------------------------------------
#Source and object files
SRCS		= $(wildcard $(SRCS_DIR)*.c)
BNS_SRCS	= $(wildcard $(BNS_SRCS_DIR)*.c)

#Object files
OBJS		= $(addprefix $(OBJS_DIR), $(notdir $(SRCS:.c=.o)))
BNS_OBJS	= $(addprefix $(OBJS_DIR), $(notdir $(BNS_SRCS:.c=.o)))
#---------------------------------------------------------------------------------

#Default Make
all: $(OBJS_DIR) $(LIBFT) $(TARGET) bonus

#Compile
$(TARGET): $(OBJS) $(MAIN_DIR)$(TARGET).c
	@$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@
	@$(eval COUNT=$(shell echo $$(($(COUNT)+1))))
	@echo "]"
	@echo "$(GREEN)Push_Swap .exe created ->$(RESET)"
	@echo "$(COUNT) files compiled"
	@echo "____________________\n"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@if [ $(COUNT) = 0 ]; then echo -n "$(GREEN)Compiling Push_Swap$(RESET)\n["; fi
	@echo -n "$(YELLOW)$(IGREY).$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c  $< -o $@
	@$(eval COUNT=$(shell echo $$(($(COUNT)+1))))

$(LIBFT):
	@make --no-print-directory all -C $(LIB_DIR)

#Bonus command
bonus: $(OBJS_DIR) $(CHECKER)

$(CHECKER): $(OBJS) $(BNS_OBJS) $(MAIN_DIR)$(CHECKER).c
	@$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@
	@$(eval COUNT_BONUS=$(shell echo $$(($(COUNT_BONUS)+1))))
	@echo "$(GREEN)checker .exe added ->$(RESET)"
	@echo "$(COUNT_BONUS) files compiled"
	@echo "____________________\n"

$(OBJS_DIR)%.o: $(BNS_SRCS_DIR)%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c  $< -o $@
	@$(eval COUNT_BONUS=$(shell echo $$(($(COUNT_BONUS)+1))))

#Directories
$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(BNS_OBJS_DIR):
	@mkdir -p $(BNS_OBJS_DIR)

#Clean only Object files
clean:
	@rm -rf $(OBJS_DIR) $(BNS_OBJS_DIR)
	@make --no-print-directory clean -C $(LIB_DIR)

#Full Clean, Object and Binary files
fclean: clean
	@rm -f $(TARGET)
	@rm -f $(CHECKER)
	@rm -f $(LIBFT)

#Remake
re: fclean all

#Non-File Targets
.PHONY: all bonus clean fclean re
