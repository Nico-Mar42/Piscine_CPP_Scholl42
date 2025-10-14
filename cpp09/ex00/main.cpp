#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]){
	if(argc != 2) {
		std::cerr << "not enough parameter"<< std::endl << std::endl;
		return 1;
	}

	std::string data = "data.csv";

	std::cout << YELLOW << "TEST DE BITCOINEXCHANGE" << RESET<< std::endl << std::endl;

	std::map<std::string, float> data_map = make_map(data.c_str());
	print_rslt(data_map, argv[1]);
	
}