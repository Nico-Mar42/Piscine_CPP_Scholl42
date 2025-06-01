#ifndef FIXED_HPP
	#define FIXED_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <fstream>
# include <sstream>

class Fixed
{
	//public:
	//protected:
	//private:

	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);

	private:
		int _nbr;
		static const int bits_nbr;
};

#endif