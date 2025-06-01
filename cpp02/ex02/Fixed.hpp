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
	//public:
	//protected:
	//private:

	public:
		Fixed();
		Fixed(int const nbr);
		Fixed(float const nbr);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat( void ) const;
		int toInt( void ) const;

	private:
		int _nbr;
		static const int bits_nbr;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif