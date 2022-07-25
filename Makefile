# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikarjala <ikarjala@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 16:57:32 by ikarjala          #+#    #+#              #
#    Updated: 2022/07/25 16:33:43 by ikarjala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ROOT	:= ./
NAME	:= libftprintf.a
BIN		= $(ROOT)$(NAME)
SO		= $(NAME:.a=.so)

CFUNC	= \
ft_printf

SRC_DIR		= $(ROOT)src/
OBJ_DIR		= $(ROOT)obj/
INC_DIR		= $(SRC_DIR)

SRC			= $(CFUNC:%=$(SRC_DIR)%.c)
OBJ			= $(CFUNC:%=$(OBJ_DIR)%.o)
INCLUDE		= $(addprefix -I , $(INC_DIR))
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror
DEBUG_FLAGS	= -Wimplicit -Wconversion -g -fsanitize=address
SOFLAGS		= -nostartfiles -fPIC
CC			= clang
AR			= ar -cr

.PHONY: all clean fclean re db debug so $(PRE_BUILD_MESSAGE)

all: $(NAME)
$(NAME): $(OBJ) Makefile
	@echo	$(BMSG_AR)
	@$(AR)		$(BIN) $(OBJ)
	@ranlib		$(BIN)
	@echo	$(BMSG_FIN)
$(SO): NAME := $(SO)
$(SO): $(NAME)

$(OBJ): $(OBJ_DIR)%.o:$(SRC_DIR)%.c Makefile
	@printf	"$<    \t\t... "
	@$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@
	@echo	"DONE"

clean:
	@echo	'Cleaning objects...'
	@$(RM) $(OBJ)
fclean: clean
	@echo	'Removing binaries...'
	@$(RM) $(BIN) $(BIN:.a=.so)
re: fclean all

so: CFLAGS += $(SOFLAGS)
so: BMSG_FORM := SO (dylib)
so: $(SO)

db: debug
debug: CFLAGS += $(DEBUG_FLAGS)
debug: BMSG_FORM := =DEBUG=
debug: $(NAME)

$(PRE_BUILD_MESSAGE):
	@echo	$(BMSG_BIN)
	@echo	$(BMSG_CC)
	@echo	$(BMSG_RELINK)

BMSG_BIN	= '$(COL_HL)$(NAME) :: Starting $(BMSG_FORM) build... $(COL_NUL)'
BMSG_FORM	:= deploy

BMSG_CC		= '$(COL_HL)$(NAME) :: Using $(CC) with $(CFLAGS) $(COL_NUL)'
BMSG_RELINK	= '$(COL_HL)$(NAME) :: Compiling C objects:'
BMSG_AR		= '$(COL_HL)$(NAME) :: Linking... { $(AR) }'
BMSG_FIN	= '$(COL_CS)$(NAME) :: Build success! $(COL_NUL)'

#COL_HL		:=\033[0;33m
#COL_CS		:=\033[0;32m
#COL_NUL	:=\033[0;0m

##	UTILS ====
CMD_NORME	= norminette -R CheckForbiddenSourceHeader
norme:
	$(CMD_NORME) $(SRC_DIR)*.c $(INC_DIR)*.h
