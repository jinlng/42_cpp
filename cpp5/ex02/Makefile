NAME        = chaos

CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98 -MMD -MP

INC_DIR     = includes
SRC_DIR     = srcs
OBJ_DIR     = objs

CXXFLAGS   += -I $(INC_DIR)

SRCS        = main.cpp \
              Bureaucrat.cpp \
              AForm.cpp \
              ShrubberyCreationForm.cpp \
              RobotomyRequestForm.cpp \
              PresidentialPardonForm.cpp

OBJS        = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
DEPS        = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f *_shrubbery

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re