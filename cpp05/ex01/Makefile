NAME	:= Bureaucrat

CC		:= c++
RM		:= rm
FLAGS	:= -std=c++98 -g -Wall -Werror -Wextra

INCLUDE := ./include
SRC_DIR	:= ./src
OBJ_DIR	:= ./obj
MAINFILE := main.cpp

HEADERS := -I $(INCLUDE)

SRC		:= Bureaucrat.cpp Form.cpp
 
SRCS    := $(patsubst %.cpp, $(SRC_DIR)/%.cpp, $(SRC))
OBJS    := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

all: $(NAME) $(MAINFILE)

$(NAME):	$(OBJS) $(MAINFILE)
	$(CC) $(HEADERS) $(OBJS) $(MAINFILE) -o $(NAME) $(FLAGS)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(HEADERS)  -c $< -o $@ $(FLAGS)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) -rdf $(OBJ_DIR)

fclean:	clean
	@$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
