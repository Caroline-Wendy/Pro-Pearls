/*From Programming Perls, By C.L.Wang*/

#include <iostream>
#include <bitset>
#include <fstream>

using namespace std;

int main(void){

	const unsigned long int bit_length = 1000000;
	const std::string file_name = "phone_number.txt";
	const std::string sorted_name = "sorted_number.txt";
	std::string c_phone_number;
	unsigned long int phone_number;

	/*initialize set to empty*/
	bitset<bit_length> bit_vector;
	bit_vector.reset();
	if(bit_vector.any()){
		std::cerr << "Sorry, the bit vector is not empty! " << std::endl;
		return -1;
	}

	/*insert present elements into set*/
	std::fstream ifs(file_name, ios::in);
	if(ifs.fail()){
		std::cerr << "Sorry, failed to open " << file_name << "! " << std::endl;
		return -1;
	}

	while(std::getline(ifs, c_phone_number)){
		phone_number = atoi(c_phone_number.c_str());
		bit_vector[phone_number] = 1;
	}

	ifs.close();

	/*write sorted output*/
	std::ofstream ofs(sorted_name, ios::out);
	if(ofs.fail()){
		std::cerr << "Sorry, failed to open " << sorted_name << "! " << std::endl;
		return -1;
	}

	std::cout << "The order: " << std::endl;
	for(unsigned long int i=0; i<bit_length; i++){
		if(bit_vector[i] == 1){
			std::cout << "\t" << i << std::endl;
			ofs << i << std::endl;
		}
	}

	ofs.close();

	return 0;
}