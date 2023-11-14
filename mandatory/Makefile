# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 14:37:14 by xmatute-          #+#    #+#              #
#    Updated: 2023/11/03 17:05:42 by xmatute-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

define ASCIIART
 
          -~~~~-
         |O __ O|
      -__|_\__/_|__-
      ---(__/\__)---
        /||~--~||\\
       / ||    || \\
      |  `'    `'  |
    _/ /\\__    __/\\ \_
  ~~~~~    ~~~~    ~~~~~ 

endef
export ASCIIART

NAME := WebServer

SRC :=	main.cpp	\

OBJ := $(SRC:%.cpp=%.o)

HEADER := 

# INTERFACES := 

CLASSES := Config Location WebServer Server Port

CLASSES_SRC := $(CLASSES:%=%.cpp)

CLASSES_OBJ := $(CLASSES:%=%.o)

CLASSES_HEADER := $(CLASSES:%=%.hpp) $(INTERFACES:%=%.hpp)

CXX		:=	c++

CPPFLAGS:=	-Wall -Wextra -Werror -std=c++98 -pedantic

SANI 	:= -fsanitize=address -g3

CPPFLAGS:= $(CPPFLAGS) $(EFLAGS)

RM 		:= rm -rf

WHITE = \033[0;37m
RED = \033[0;31m
CYAN = \033[0;36m
GREEN = \033[0;32m
MAGENTA = \033[0;35m

all : $(NAME)

$(NAME): $(CLASSES_OBJ) $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) $(CLASSES_OBJ) -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled...$(WHITE)"
	@echo "$(MAGENTA)$$ASCIIART$(WHITE)"

$(OBJ):%.o: %.cpp $(HEADER) $(HEADERS) $(CLASSES_OBJ)
	@echo "compilando $<..."
	$(CXX) $(CPPFLAGS) -c $< -o $@
	@echo "$@ compilado!"


$(CLASSES_OBJ): %.o: %.cpp $(HEADERS) $(CLASSES_HEADER)
	@echo "compilando $<..."
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@
	@echo "$@ compilado!"
	
clean : 
	$(RM) $(OBJ) $(CLASSES_OBJ)
	@echo "$(RED)clean done...$(WHITE)"

fclean : clean
		$(RM) $(NAME)
		@echo "$(RED)fclean done...$(WHITE)"

re : fclean all

sani:
	$(MAKE) EFLAGS='$(SANI)' all

flagless:
	$(MAKE) CPPFLAGS='' all

commit:
	git add $(SRC) $(CLASSES_SRC) $(CLASSES_HEADER) $(HEADER) $(HEADERS)  ./Makefile
	git commit -m "commit general de $(NAME)"
	git push
	git status

test: all
	./$(NAME) 


.PHONY : all clean fclean re sani flagless normi commit test