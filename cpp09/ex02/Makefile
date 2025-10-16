# Variables
CC = c++
CFLAGS = -g -Wall -Wextra -Werror -std=c++98
NAME = PmergeMe

# Sources et objets
SRC = main.cpp PmergeMe.cpp utils.cpp\

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

fclean: clean
	rm -f $(NAME)

re: fclean all
