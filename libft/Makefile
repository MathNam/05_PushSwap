#Compiler and Linker
CC          = cc

#Target .a
TARGET		= libft.a

#Directories, Sources, Objects
SRCS_DIR	= srcs/
SUB_DIRS	= lib/ gnl/ ftprintf/
OBJS_DIR	= objs/

#Flags, Libraries and Includes
INCLUDES	= -I ./inc/
CFLAGS		= -Wall -Werror -Wextra

#Colors
RESET = \033[0;39m
GRAY = \033[0;90m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[0;93m
BLUE = \033[1;34m
PURPLE = \033[1;35m
CYAN = \033[0;96m
WHITE = \033[0;97m

#Inverted, i.e. colored backgrounds
IGREY=\033[40m
IRED=\033[41m
IGREEN=\033[42m
IYELLOW=\033[43m
IBLUE=\033[44m
IPURPLE=\033[45m
ICYAN=\033[46m
IWHITE=\033[47m

#Counter
COUNT = 0

#---------------------------------------------------------------------------------
#Do not edit below this line
#---------------------------------------------------------------------------------

#---------------------------------------------------------------------------------
#Source and object files
SRCS		:= $(foreach dir, $(SUB_DIRS), $(wildcard $(SRCS_DIR)$(dir)*.c))

#Object files
OBJS		:= $(addprefix $(OBJS_DIR),$(notdir $(SRCS:.c=.o)))
#---------------------------------------------------------------------------------

#Default Make
all: $(OBJS_DIR) $(TARGET)

#Compile
$(TARGET): $(OBJS_DIR) $(OBJS)
	@ar rcs $(TARGET) $(OBJS)
	@echo "]"
	@echo "$(BLUE)libft created ->$(RESET)"
	@echo "$(COUNT) files compiled"
	@echo "____________________\n"

$(OBJS_DIR)%.o : $(SRCS_DIR)/*/%.c
	@if [ $(COUNT) = 0 ]; then echo -n "$(BLUE)Compiling Libft$(RESET)\n["; fi
	@echo -n "$(YELLOW)$(IGREY).$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@$(eval COUNT=$(shell echo $$(($(COUNT)+1))))

#Directories
$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

#Clean only Object files
clean:
	@rm -rf $(OBJS_DIR)

#Full Clean, Object and Binary files
fclean: clean
	@rm -f $(TARGET)

#Remake
re: fclean all

#Non-File Targets
.PHONY: all clean fclean re