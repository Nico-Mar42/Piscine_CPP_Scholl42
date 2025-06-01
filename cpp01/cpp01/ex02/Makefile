# Variables
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = HI_THIS_IS_BRAIN

# Sources et objets
SRC = main.cpp \

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
