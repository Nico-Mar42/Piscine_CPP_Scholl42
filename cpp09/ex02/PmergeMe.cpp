#include "PmergeMe.hpp"

PmergeMe::PmergeMe(): _Pmerge_list(), _Pmerge_vect(){}

PmergeMe::PmergeMe(PmergeMe &other): _Pmerge_list(), _Pmerge_vect(){
	this->_Pmerge_list = other._Pmerge_list;
	this->_Pmerge_vect = other._Pmerge_vect;
}

PmergeMe &PmergeMe::operator=(PmergeMe &other){
	this->_Pmerge_list.clear();
	this->_Pmerge_vect.clear();
	this->_Pmerge_list = other._Pmerge_list;
	this->_Pmerge_vect = other._Pmerge_vect;
	return *this;
}

PmergeMe::~PmergeMe(){};

std::list<int>	PmergeMe::get_list(){
	return _Pmerge_list;
}
std::vector<int> PmergeMe::get_vect(){
	return _Pmerge_vect;
}

void PmergeMe::sort_list(const char *argv[]){
	clock_t start, end;
	start = clock();
	
	std::list<int> big;
	std::list<int> little;
	if (!check_param(argv))
		return;
	int i = 0;
	while ( argv[i] != NULL)
	{
		if (argv[i] != NULL && argv[i + 1] == NULL){
			big.push_back(atoi(argv[i]));
			break;}
		else if (atoi(argv[i]) < atoi(argv[i + 1])){
			little.push_back(atoi(argv[i]));
			big.push_back(atoi(argv[i + 1]));
		}
		else{
			big.push_back(atoi(argv[i]));
			little.push_back(atoi(argv[i + 1]));
		}
		i++;
		i++;
	}
	this->list_big_sort(big);
	std::cout << MAGENTA << std::endl << "Print Pmerge list" << RESET << std::endl;

	if (this->list_little_insert(little) == 1)
		return;

	print_list(this->_Pmerge_list);

	end = clock();
	float millisecondes = float(end - start) / CLOCKS_PER_SEC * 1000;
	std::cout << "Temps d'exécution de sort_list : " << millisecondes << " millisecondes." << std::endl;
}

void PmergeMe::sort_vector(const char *argv[]){
	clock_t start, end;
	start = clock();
	
	std::vector<int> big;
	std::vector<int> little;
	if (!check_param(argv))
		return;
	int i = 0;
	while ( argv[i] != NULL)
	{
		if (argv[i] != NULL && argv[i + 1] == NULL){
			big.push_back(atoi(argv[i]));
			break;}
		else if (atoi(argv[i]) < atoi(argv[i + 1])){
			little.push_back(atoi(argv[i]));
			big.push_back(atoi(argv[i + 1]));
		}
		else{
			big.push_back(atoi(argv[i]));
			little.push_back(atoi(argv[i + 1]));
		}
		i++;
		i++;
	}

	this->vect_big_sort(big);
	std::cout << MAGENTA << std::endl << "Print Pmerge vector" << RESET << std::endl;

	if (this->vect_little_insert(little) == 1)
		return;

	print_vector(this->_Pmerge_vect);

	end = clock();
	float millisecondes = float(end - start) / CLOCKS_PER_SEC * 1000;
	std::cout << "Temps d'exécution de sort_vector : " << millisecondes << " millisecondes." << std::endl;
}

void PmergeMe::list_big_sort(std::list<int> &big){
	std::list<int> tmp;
	std::list<int>::iterator it = big.begin();
	std::list<int>::iterator act_it = big.begin();

	int smaller = INT_MAX;
	while(it != big.end()){
		if (smaller > *it){
			smaller = *it;
			act_it = it;}
			it++;
	}
	this->_Pmerge_list.push_back(smaller);
	big.erase(act_it);
	if(big.size() > 1)
		this->list_big_sort(big);
	if (big.size() == 1){
		act_it = big.begin();
		this->_Pmerge_list.push_back(*act_it);
		big.erase(act_it);}
}

int PmergeMe::list_little_insert(std::list<int> &l){

	std::list<int>::iterator it;
	for (size_t j = 0; j < l.size(); j++){
		size_t i = this->_Pmerge_list.size() / 2;
		std::list<int>::iterator it = find_index(l, j);
		while(i >= 0 || i < this->_Pmerge_list.size()){
			std::list<int>::iterator P_it = find_index(this->_Pmerge_list, i);
			if(*P_it == *it){
				std::cerr << RED << "Error: two numbers are equal in list" << RESET << std::endl;
				return 1;}
			else if(*it < *P_it){
				if (find_index(this->_Pmerge_list, i) == this->_Pmerge_list.begin()){
					this->_Pmerge_list.insert(P_it, *it);
					break;}
				else if (*it > *(find_index(this->_Pmerge_list, i - 1))){
					this->_Pmerge_list.insert(P_it, *it);
					break;}
				else
					i--;
			}
			else if(*it > *P_it){
				if (*it < *(find_index(this->_Pmerge_list, i - 1)) || find_index(this->_Pmerge_list, i+1) == this->_Pmerge_list.end()){
					this->_Pmerge_list.insert(P_it, *it);
					break;}
				else{
					i++;
				}
			}
		}
	}
	return 0;
}

void PmergeMe::vect_big_sort(std::vector<int> &big){
	std::vector<int> tmp;
	size_t act_i;
	int smaller = INT_MAX;
	for (size_t i = 0; i < big.size(); i++){
		if (smaller > big.at(i)){
			smaller = big.at(i);
			act_i = i;}
	}
	this->_Pmerge_vect.push_back(smaller);
	big.erase(big.begin() + act_i);
	if(big.size() > 1)
		this->vect_big_sort(big);
	if (big.size() == 1){
		this->_Pmerge_vect.push_back(big.at(0));
		big.erase(big.begin());}
}

int PmergeMe::vect_little_insert(std::vector<int> &l){

	for (size_t j = 0; j < l.size(); j++){
		size_t i = this->_Pmerge_vect.size() / 2;
		while(i >= 0 || i < this->_Pmerge_vect.size()){
			if (_Pmerge_vect.at(i) == l.at(j)){
				std::cerr << RED << "Error: two numbers are equal in vector" << RESET << std::endl;
				return 1;}
			else if (l.at(j) < _Pmerge_vect.at(i)){

				if (i == 0){
					this->_Pmerge_vect.insert(_Pmerge_vect.begin(), l.at(j));
					break;}
				else if(l.at(j) > _Pmerge_vect.at(i - 1)){
					this->_Pmerge_vect.insert(_Pmerge_vect.begin() + i, l.at(j));
					break;}
				else
					i--;
				}
			else if(l.at(j) > _Pmerge_vect.at(i)){
				if(l.at(j) <  _Pmerge_vect.at(i - 1) || (i + 1) == _Pmerge_list.size()){
					this->_Pmerge_vect.insert(_Pmerge_vect.begin() + i, l.at(j));
					break;}
				else
					i++;
			}
		}
	}
	return 0;
}	


bool check_param(const char *argv[]){

	for(int i = 0; argv[i] != NULL; i++){

		for(int j = 0; argv[i][j] != '\0'; j++){
			if (!isdigit(argv[i][j])){
			std::cerr << RED << "Error: this number ( " << argv[i];
			std::cerr << " ) is not a number" << RESET << std::endl;
			return false;
			}
		}
		if(atof(argv[i]) > INT_MAX){
			std::cerr << RED << "Error: this number ( " << argv[i];
			std::cerr << " ) is too high" << RESET << std::endl;
			return false;}
		else if (atof(argv[i]) < 0){
			std::cerr << RED << "Error: this number ( " << argv[i];
			std::cerr << " ) is negative" << RESET << std::endl;
			return false;}
	}
	return true;
}
