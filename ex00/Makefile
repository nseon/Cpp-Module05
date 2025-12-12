# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nseon <nseon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 10:54:16 by nseon             #+#    #+#              #
#    Updated: 2025/12/11 11:28:52 by nseon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	bureaucrat

# ---------------FILES--------------- #

MAKE_DIR	=	.make/

SRC_DIR		=	

OBJ			=	$(patsubst %.cpp, $(MAKE_DIR)%.o, $(SRC))

DEP			=	$(patsubst %.cpp, $(MAKE_DIR)%.d, $(SRC))

# ---------------MAIN---------------- #

SRC			=	main.cpp \
				Bureaucrat.cpp \

# --------------INCLUDES------------- #

INCS_DIR	=	
INCLUDES	=	$(INCS_DIR)

# --------------CONFIGS-------------- #

CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98 -g3 -Weverything -Wno-suggest-override -Wno-suggest-destructor-override -Wno-padded
CPPFLAGS	=	-MMD -MP $(addprefix -I, $(INCLUDES))

# --------------TARGETS-------------- #

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

$(MAKE_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(MAKE_DIR)

.PHONY: fclean
fclean:
	rm -rf $(NAME) $(MAKE_DIR)

.PHONY: re
re: fclean
	$(MAKE)

.PHONY: force
force:

-include $(DEP)

.DEFAULT_GOAL := all
