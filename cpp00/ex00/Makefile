# Variables
CPP = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = megaphone

# Sources et objets
SRC = megaphone.cpp

# Règle par défaut
all: $(NAME)

# Compilation des fichiers objets
%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

# Création de l'exécutable
$(NAME): $(SRC:.cpp=.o)
	$(CPP) $(CFLAGS) -o $@ $^

# Nettoyage
clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
