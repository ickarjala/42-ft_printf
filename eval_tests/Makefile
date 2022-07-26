# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikarjala <ikarjala@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 16:57:32 by ikarjala          #+#    #+#              #
#    Updated: 2022/07/26 14:47:20 by ikarjala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ROOT	:= ./
NAME	:= printf_unit_tests
BIN		= $(ROOT)$(NAME)

CFUNC	= \
main

SRC_DIR		= $(ROOT)
OBJ_DIR		= $(ROOT)
INC_DIR		= $(SRC_DIR) $(LIB_DIR)
LIB_DIR		= ../

SRC			= $(CFUNC:%=$(SRC_DIR)%.c)
OBJ			= $(CFUNC:%=$(OBJ_DIR)%.o)
INCLUDE		= $(addprefix -I , $(INC_DIR))
LIBS		= $(addprefix -L , $(LIB_DIR)) $(addprefix -l, ftprintf)
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror
DEBUG_FLAGS	= -Wimplicit -Wconversion -g -fsanitize=address
CC			= clang

.PHONY: all clean fclean re db debug so $(PRE_BUILD_MESSAGE)

all: $(NAME)
$(NAME):
	make -C $(LIB_DIR)	debug
	@echo	$(PRE_BUILD_MESSAGE)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) $(LIBS) $(INCLUDE) -o $(BIN)
	@echo	$(BMSG_FIN)

clean:
	@echo	'Cleaning objects...'
	@$(RM) $(OBJ)
fclean: clean
	@echo	'Removing binaries...'
	@$(RM) $(BIN) $(BIN:.a=.so)
re: fclean all

run: all
	@echo	"Running unit tests ..."
	@$(BIN)

$(PRE_BUILD_MESSAGE):
	@echo	$(BMSG_BIN)
	@echo	$(BMSG_CC)
	@echo	$(BMSG_RELINK)

BMSG_BIN	= '$(COL_HL)$(NAME) :: Starting $(BMSG_FORM) build... $(COL_NUL)'
BMSG_FORM	:= deploy

BMSG_CC		= '$(COL_HL)$(NAME) :: Using $(CC) with $(CFLAGS) $(COL_NUL)'
BMSG_RELINK	= '$(COL_HL)$(NAME) :: Compiling C objects:'
BMSG_FIN	= '$(COL_CS)$(NAME) :: Build success! $(COL_NUL)'

#COL_HL		:=\033[0;33m
#COL_CS		:=\033[0;32m
#COL_NUL	:=\033[0;0m
