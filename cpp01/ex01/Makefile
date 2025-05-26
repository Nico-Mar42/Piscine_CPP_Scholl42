# Variables
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = Moar_brainz!

# Sources et objets
SRC = main.cpp Zombie.cpp ZombieHorde.cpp \

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
