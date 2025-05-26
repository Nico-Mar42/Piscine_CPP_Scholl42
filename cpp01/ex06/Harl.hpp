#ifndef HARL_HPP
	#define HARL_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <fstream>
# include <sstream>

class Harl
{
	//public:
	//protected:
	//private:

	public:
		Harl();
		void complain (std::string lvl);
		~Harl();

	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
};

#endif