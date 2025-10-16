#!/bin/zsh

# Tests valides
./RPN "2 3 4 + *"        # 14
./RPN "9 8 - 2 *"        # 2
./RPN "5 6 7 + * 8 -"    # 57
./RPN "3 3 * 2 /"        # 4
./RPN "1 2 + 3 + 4 + 5 +" # 15

# Cas limites et erreurs
./RPN ""                  # Expression vide
./RPN "2 +"               # Pas assez d'opérandes
./RPN "+"                 # Pas d'opérandes
./RPN "2 3 4 +"           # Trop d'opérandes
./RPN "5 0 /"             # Division par zéro
./RPN "2 a +"             # Caractère non autorisé
./RPN "2   3   +"         # Espaces multiples
./RPN "1 2 +     3 + 4 + 5 + 6 + 7 + 8 + 9 +" # Expression longue
