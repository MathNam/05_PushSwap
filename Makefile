#Compiler and Linker
CC          = gcc

#Target .exe
TARGET		= push_swap

#Directories, Source, Objects, Lib
SRCS_DIR	= srcs/
OBJS_DIR	= objs/
LIB_DIR		= libft/

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

#---------------------------------------------------------------------------------
#Do not edit below this line
#---------------------------------------------------------------------------------

#---------------------------------------------------------------------------------
#Source and object files
SRCS		= $(wildcard $(SRCS_DIR)*.c)

#Object files
OBJS		= $(addprefix $(OBJS_DIR), $(notdir $(SRCS:.c=.o)))
#---------------------------------------------------------------------------------

#Default Make
all: $(OBJS_DIR) $(LIBFT) $(TARGET)

#Compile
$(TARGET): $(OBJS)
	@$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@
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

#Directories
$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

#Bonus command
bonus: all

#Clean only Object files
clean:
	@rm -rf $(OBJS_DIR)
	@make --no-print-directory clean -C $(LIB_DIR)

#Full Clean, Object and Binary files
fclean: clean
	@rm -f $(TARGET)
	@rm -f $(LIBFT)

#Remake
re: fclean all

#Non-File Targets
.PHONY: all clean fclean re
