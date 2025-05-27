# include <iostream>
# include <string>
# include <cstdlib>
# include <fstream>
# include <sstream>

int main(int argc, char **argv)
{
	std::string in_file = argv[1];
	std::string out_file = argv[1] + std::string(".replace");

	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <filename> <string to replace> <new string>" << std::endl;
		return 1;
	}

	std::ifstream in(in_file.c_str());
	if (!in.is_open()) {
		std::cerr << "Error opening file: " << in_file << std::endl;
		return 1;
	}
	std::stringstream buffer;
	std::string content;
	buffer << in.rdbuf();
	content = buffer.str();
	in.close();

	std::string to_replace = argv[2];
	std::string new_string = argv[3];
	size_t pos = 0;
	while ((pos = content.find(to_replace, pos)) != std::string::npos) 
	{
		content = content.substr(0, pos) + new_string + content.substr(pos + to_replace.length());
		pos += new_string.length(); // Move past the new string to avoid infinite loop
	}

	std::ofstream file(out_file.c_str());
	if (!file.is_open()) {
		std::cerr << "Error opening file for writing: " << out_file << std::endl;
		return 1;
	}
	file << content;
	if (!file) {
		std::cerr << "Error writing to file: " << out_file << std::endl;
		return 1;
	}
	file.close();
	return 0;
}