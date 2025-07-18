# Variables
CC = c++
CFLAGS = -g -Wall -Wextra -Werror -std=c++98
NAME = Serialization

# Sources et objets
SRC = main.cpp Serializer.cpp \

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
