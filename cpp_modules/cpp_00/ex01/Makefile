NAME = phonebook

BIN			= bin
SRC			= src/main.cpp\
			src/Contact.cpp\
			src/PhoneBook.cpp
OBJS		= $(SRC:src/%.cpp=$(BIN)/%.o)
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -Iinclude
RM			= rm -rf

all: $(NAME)

$(NAME): $(BIN) $(OBJS)
	${CXX} $(OBJS) -o $(NAME) 

$(BIN)/%.o: src/%.cpp
	${CXX} $(CXXFLAGS) -c $< -o $@

$(BIN):
	mkdir -p $(BIN)

clean:
	$(RM) $(BIN)

fclean: clean
	$(RM) $(NAME)

re: fclean all

show:
	@printf "UNAME		: $(UNAME)\n"
	@printf "NAME  		: $(NAME)\n"
	@printf "CXX		: $(CXX)\n"
	@printf "SRC		: $(SRC)\n"
	@printf "OBJS		: $(OBJS)\n"

.PHONY: all clean fclean re show