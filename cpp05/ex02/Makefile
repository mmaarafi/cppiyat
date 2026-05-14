NAME = program

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp
OBJ = $(SRC:%.cpp=obj/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

obj/%.o: %.cpp Bureaucrat.hpp AForm.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp
	mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re