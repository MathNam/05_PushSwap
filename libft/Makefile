#______________________________________________________________________________#
############################### Target Names ###################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

# Name
NAME = libft.a

#______________________________________________________________________________#
############################### Compiler #######################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

# Compiler
CC = cc 

# Compiler Flags
CFLAGS = -Wall -Wextra -Werror

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

# Bold
BYELLOW = \033[1;33m
BGREEN = \033[1;32m
BBLUE = \033[1;34m
BRED = \033[1;31m
BPURPLE = \033[1;35m
BCYAN = \033[1;36m
BBLACK = \033[1;30m
BWHITE = \033[1;37m

# Background
On_Black = \033[40m       # Black
On_Red = \033[41m         # Red
On_Green = \033[42m       # Green
On_Yellow = \033[43m      # Yellow
On_Blue = \033[44m        # Blue
On_Purple = \033[45m      # Purple
On_Cyan = \033[46m        # Cyan
On_White = \033[47m       # White

# One Line Output
OL =\e[1A\r\033[K

#______________________________________________________________________________#
############################### Includes #######################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

INC_DIR = ./inc
INCLUDES += -I $(INC_DIR)

#______________________________________________________________________________#
############################### Headers ########################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

HEADER += libft.h

vpath %.h $(INC_DIR)

#______________________________________________________________________________#
############################### Path Sources ###################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

SRCS_DIR = ./srcs
PATH_SRCS_CTYPE = $(SRCS_DIR)/ctype
PATH_SRCS_STR = $(SRCS_DIR)/str
PATH_SRCS_MEM = $(SRCS_DIR)/mem
PATH_SRCS_IO = $(SRCS_DIR)/io
PATH_SRCS_STD = $(SRCS_DIR)/std
PATH_SRCS_PRINTF = $(SRCS_DIR)/io/ftprintf
PATH_SRCS_GNL = $(SRCS_DIR)/gnl

#______________________________________________________________________________#
############################### SOURCES ########################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

# ctype
SRCS += ft_isalnum.c
SRCS += ft_isalpha.c
SRCS += ft_isascii.c
SRCS += ft_isdigit.c
SRCS += ft_isprint.c
SRCS += ft_issign.c
SRCS += ft_isspace.c
SRCS += ft_tolower.c
SRCS += ft_toupper.c

# string
SRCS += ft_strchr.c
SRCS += ft_strdup.c
SRCS += ft_striteri.c
SRCS += ft_strjoin.c
SRCS += ft_strlcat.c
SRCS += ft_strlcpy.c
SRCS += ft_strlen.c
SRCS += ft_strmapi.c
SRCS += ft_strncmp.c
SRCS += ft_strnstr.c
SRCS += ft_strrchr.c
SRCS += ft_strtrim.c
SRCS += ft_substr.c

# mem
SRCS += ft_bzero.c
SRCS += ft_calloc.c
SRCS += ft_memchr.c
SRCS += ft_memcmp.c
SRCS += ft_memcpy.c
SRCS += ft_memmove.c
SRCS += ft_memset.c

# io
SRCS += ft_putchar_fd.c
SRCS += ft_putendl_fd.c
SRCS += ft_putnbr_fd.c
SRCS += ft_putstr_fd.c

# std
SRCS += ft_atoi_base.c
SRCS += ft_atoi.c
SRCS += ft_index.c
SRCS += ft_ischarset.c
SRCS += ft_itoa.c
SRCS += ft_split.c

# ft_printf
SRCS += list_ft.c
SRCS += ft_printf_util.c
SRCS += parse_format.c
SRCS += format_error.c
SRCS += conversion.c
SRCS += mod_p1.c
SRCS += mod_p2.c
SRCS += output.c
SRCS += process_arg_p1.c
SRCS += process_arg_p2.c
SRCS += ft_printf.c

# get_next_line
SRCS += get_next_line_util.c
SRCS += get_next_line.c

#______________________________________________________________________________#
############################### Attribution ####################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

vpath %.c $(PATH_SRCS_CTYPE)
vpath %.c $(PATH_SRCS_STR)
vpath %.c $(PATH_SRCS_MEM)
vpath %.c $(PATH_SRCS_IO)
vpath %.c $(PATH_SRCS_STD)
vpath %.c $(PATH_SRCS_PRINTF)
vpath %.c $(PATH_SRCS_GNL)

#______________________________________________________________________________#
############################### Objects ########################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

OBJS_DIR = ./objs
OBJS = $(patsubst %.c, $(OBJS_DIR)/%.o, $(SRCS))

#______________________________________________________________________________#
############################### Counter ########################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

TOTAL	= $(words $(SRCS))
COUNT	= 0

#______________________________________________________________________________#
############################### Rules ##########################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

#_____Build_____#
all: where $(OBJS_DIR) $(NAME)
	@echo "--▶ $(BGREEN)all\t$(GREEN)done$(NC)"
	@echo "--------------------------------------------------"

$(NAME): $(OBJS) 
	@ar rcs $@ $^
    #-----Output-----#
	@printf "$(OL)$(BCYAN)[%2d/%2d] %3d%%\t$(CYAN)All files compiled\n$(NC)" $(COUNT) $(TOTAL) $(PERCENT)
	@echo "▶ $(BGREEN)$(NAME)\t$(GREEN)Library created$(NC)"

$(OBJS): $(OBJS_DIR)/%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
    #-----Output-----#
	@if [ $(COUNT) = 0 ]; then echo ""; fi
	@$(eval COUNT=$(shell echo $$(($(COUNT)+1))))
	@$(eval PERCENT:=$(shell echo $$((100*$(COUNT)/$(TOTAL)))))
	@printf "$(OL)$(BCYAN)[%2d/%2d] %3d%%\t$(CYAN)Compiling %s\n$(NC)" $(COUNT) $(TOTAL) $(PERCENT) $< 

$(OBJS_DIR):
	@mkdir $@

#_____Clean_____#
clean: where
	@rm -rf $(OBJS_DIR)
    #-----Output-----#
	@echo "▶ $(BYELLOW)clean\t$(YELLOW)Object files removed from libft$(NC)"
	@echo "--▶ $(BYELLOW)clean$(YELLOW) done$(NC)"

fclean: clean
	@rm -f $(NAME)
    #-----Output-----#
	@echo "▶ $(BRED)fclean\t$(RED)Library removed$(NC)"
	@echo "--▶ $(BRED)fclean$(RED) done$(NC)"

# Current Make
where:
	@echo "$(BBLACK)>libft $(NC)"

re: fclean all

.PHONY: all clean fclean re
