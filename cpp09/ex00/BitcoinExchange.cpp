#include "BitcoinExchange.hpp"

bool split_by_char(const std::string& line, std::string& date, std::string& value, char c);
bool isValidDate(const std::string &date);
bool check_history(std::string date, std::string value);
bool is_empty(const std::string &s);

std::map<std::string ,float> make_map(char const *data_name){
	std::string in_file = data_name;
	std::map<std::string ,float> data;

	std::ifstream in(in_file.c_str());
	if (!in.is_open()) {
		std::cerr << RED << "Error opening file: " << in_file << RESET<< std::endl << std::endl;
		return data;
	}
	std::stringstream buffer;
	buffer << in.rdbuf();
	std::string line;
	while(std::getline(buffer, line)){
		std::string date;
		std::string value;
		split_by_char(line, date, value, ',');
		data[date] = atof(value.c_str());
	}
	return data;
}

void print_rslt(std::map<std::string ,float> data, std::string histo){
	std::string in_file = histo;

	std::ifstream in(in_file.c_str());
	if (!in.is_open()) {
		std::cerr << RED << "Error opening file: " << in_file << RESET<< std::endl << std::endl;
		return;
	}
	std::stringstream buffer;
	buffer << in.rdbuf();
	std::string line;
	while(std::getline(buffer, line)){
		if (isdigit(line[0]) == false){
			std::cerr << RED << "Syntax Error in " << line << RESET<< std::endl << std::endl;
			continue;}
		std::string date;
		std::string value;
		if (split_by_char(line, date, value, '|') == false)
			continue;
		if (check_history(date, value) == false)
			continue;
		
		std::map<std::string, float>::iterator it = data.lower_bound(date);
		if (it == data.begin() && it->first != date)
		{
			 std::cerr << RED << "Error: no earlier date found." << RESET<< std::endl << std::endl;
		}
		else
		{
			float f_value;
			
			if (it == data.end() || it->first != date)
				--it;
			f_value = atof(value.c_str());
			std::cout << GREEN << date << " => " << value << " = ";
			std::cout << atof(value.c_str()) * it->second << RESET<< std::endl << std::endl;
		}
	}
}

bool check_history(std::string date, std::string value){

	if(isValidDate(date) == false){
		std::cerr << RED << "This date: " << date <<" does not exist" << RESET<< std::endl << std::endl;
		return false;
	}
	if(atoi(date.substr(0,4).c_str()) < 2009 || date == "2009-01-01"){
		std::cerr << RED << "This date: " << date <<" is earlier than the creation of Bitcoin" << RESET <<std::endl;
		return false;
	}
	if(atof(value.c_str()) < 0 || atof(value.c_str()) > 1000){
		std::cerr << RED << "Incorrect Bitcoin amount: " << value << RESET<< std::endl << std::endl;
		return false;
	}
	return true;
}

bool isValidDate(const std::string &date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-'){
        return false;}

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year <= 0 || month < 1 || month > 12 || day < 1 || day > 31){
        return (false);}

    struct tm timeinfo = {};
    timeinfo.tm_year = year - 1900;
    timeinfo.tm_mon = month - 1;
    timeinfo.tm_mday = day;
    timeinfo.tm_hour = 12;

    time_t t = mktime(&timeinfo);
    if (t == -1){
        return (false);}

    return (timeinfo.tm_year == year - 1900 &&
            timeinfo.tm_mon == month - 1 &&
            timeinfo.tm_mday == day);
}

bool split_by_char(const std::string& line, std::string& date, std::string& value, char c) {
	size_t pos = line.find(c);

	if (pos != std::string::npos) {
		if (pos <= 0){
			std::cerr << RED << "Syntax Error in " << line << RESET<< std::endl << std::endl;
			date = "";
			value = "";
			return false;
		}
		else
			date = line.substr(0, pos - 1);

		if ((pos + 1) >= line.size()){
			std::cerr << RED << "Syntax Error in " << line << RESET<< std::endl << std::endl;
			date = "";
			value = "";
			return false;
		}
		else
			value = line.substr(pos + 2);
	} 
	else {
		std::cerr << RED << "Error: delimiter " << c << " not found in the line." << RESET<< std::endl << std::endl;
		date = "";
		value = "";
		return false;
	}
	if (c == '|'){
		for (size_t i = 0; i < value.length(); i++) {
			if (!isdigit(value[i]) && value[i] != '.' && value[i] != '-') {
				std::cerr << RED << "Syntax Error in  " << line << RESET<< std::endl << std::endl;
				return false;
			}
		}
	}
	return true;
}

//bool is_empty(const std::string &s){
//	if (s == NULL)

//	for (std::string::const_iterator it = s.begin(); it < s.end(); it++)
//	{
//		if (!isspace(*it))
//			return false;
//	}
//	return true;
//}