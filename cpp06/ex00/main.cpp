
#include "Scalar_Types.hpp"
#include "ScalarConverter.hpp"

#include <iostream>
#include "ScalarConverter.hpp"  // Ton header avec la classe ScalarConverter

int main() {
    const char* tests[] = {
        "'a'",      // char alphabétique
        "'1'",      // char chiffre
        "' '",      // espace char
        "0",        // int zéro
        "42",       // int positif
        "-42",      // int négatif
        "2147483647",   // INT_MAX
        "-2147483648",  // INT_MIN
        "2147483648.0f",   // hors limite int
        "2147483648.0",   // hors limite int
        "0.0f",     // float simple
        "-4.2f",    // float négatif
        "123.0f",   // float avec .0
        "4.2",      // double simple
        "-4.2",     // double négatif
        "123.0",    // double avec .0
        "abc",      // invalide
        "123abc",   // invalide
        "''",       // quotes vides
        "'ab'",     // trop long char
        "12.34.56", // mal formé
        "+",        // signe seul
        "-",        // signe seul
        "f",        // lettre seule
        ".",        // point seul
        NULL
    };

    for (int i = 0; tests[i] != NULL; ++i) {
		std::cout << "\033[32mTest input: " << "\033[0m" << "\033[31m" << tests[i] << "\033[0m" << std::endl;
        ScalarConverter::convert(std::string(tests[i]));
        std::cout << "-----------------------------" << std::endl;
    }

    return 0;
}
