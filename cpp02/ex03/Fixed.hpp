#ifndef FIXED_HPP
	#define FIXED_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <fstream>
# include <sstream>
# include <cmath>

class Fixed
{
public:
	// ===========================
	// Constructeurs / Destructeur
	// ===========================
	// Constructeur par défaut
	Fixed();
	// Constructeur à partir d'un entier
	Fixed(int const nbr);
	// Constructeur à partir d'un flottant
	Fixed(float const nbr);
	// Constructeur de copie
	Fixed(const Fixed& other);
	// Destructeur
	~Fixed();

	// ===========================
	// Opérateurs d'affectation
	// ===========================
	Fixed& operator=(const Fixed& other);

	// ===========================
	// Opérateurs de comparaison
	// ===========================
	// Supérieur à
	bool operator>(const Fixed& other) const;
	// Inférieur à
	bool operator<(const Fixed& other) const;
	// Supérieur ou égal à
	bool operator>=(const Fixed& other) const;
	// Inférieur ou égal à
	bool operator<=(const Fixed& other) const;
	// Égal à
	bool operator==(const Fixed& other) const;
	// Différent de
	bool operator!=(const Fixed& other) const;

	// ===========================
	// Opérateurs arithmétiques
	// ===========================
	// Addition
	Fixed operator+(const Fixed& other) const;
	// Soustraction
	Fixed operator-(const Fixed& other) const;
	// Multiplication
	Fixed operator*(const Fixed& other) const;
	// Division
	Fixed operator/(const Fixed& other) const;

	// ===========================
	// Opérateurs d'incrémentation / décrémentation
	// ===========================
	// Pré-incrémentation
	Fixed& operator++();
	// Post-incrémentation
	Fixed operator++(int);
	// Pré-décrémentation
	Fixed& operator--();
	// Post-décrémentation
	Fixed operator--(int);

	// ===========================
	// Fonctions membres statiques utilitaires
	// ===========================
	// Retourne la référence du plus petit des deux (const)
	static Fixed const &min(Fixed const &a, Fixed const &b);
	// Retourne la référence du plus grand des deux (const)
	static Fixed const &max(Fixed const &a, Fixed const &b);
	// Retourne la référence du plus petit des deux
	static Fixed &min(Fixed &a, Fixed &b);
	// Retourne la référence du plus grand des deux
	static Fixed &max(Fixed &a, Fixed &b);

	// ===========================
	// Accesseurs / Mutateurs
	// ===========================
	// Retourne la valeur brute stockée
	int getRawBits(void) const;
	// Définit la valeur brute stockée
	void setRawBits(int const raw);

	// ===========================
	// Fonctions de conversion
	// ===========================
	// Convertit la valeur en float
	float toFloat(void) const;
	// Convertit la valeur en int
	int toInt(void) const;

private:
	// Valeur entière stockée
	int _nbr;
	// Nombre de bits de la partie fractionnaire (constante)
	static const int bits_nbr;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif