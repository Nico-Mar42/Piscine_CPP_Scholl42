# Variables
CC = c++
CFLAGS = -g -Wall -Wextra -Werror -std=c++98
NAME = scalar_types

# Sources et objets
SRC = main.cpp ScalarConverter.cpp

# Règle par défaut
all: $(NAME)

# Compilation des fichiers objets
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Création de l'exécutable
$(NAME): $(SRC:.cpp=.o)
	$(CC) $(CFLAGS) -o $@ $^

# Nettoyage
clean:
	rm -f *.o
	rm -f *_shrubbery

fclean: clean
	rm -f $(NAME)

re: fclean all
