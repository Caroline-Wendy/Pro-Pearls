/*From Programming Perls, By C.L.Wang*/
/*两个约束条件: 一是只能缺少1个数据, 二是最大值应满足2的倍数.*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>

using namespace std;

bool find_lost_number(const vector<int>& number_array, int& lost_number){

	/*初始化*/
	std::bitset<32> lost_number_bit;
	unsigned int num_length = number_array.size();
	vector<std::bitset<32> > num_bit_array(num_length);
	for(unsigned int i=0; i<num_length; i++){
		num_bit_array[i] = number_array[i];
	}

	unsigned int zero_num(0);
	unsigned int one_num(0);
	vector<std::bitset<32> > zero_bit_array;
	vector<std::bitset<32> > one_bit_array;

	for(unsigned int i=0; i<32; i++){

		num_length = num_bit_array.size();
		for(unsigned int j=0; j<num_length; j++){
			if(0 == num_bit_array[j][i]){
				zero_bit_array.push_back(num_bit_array[j]);
			}else{
				one_bit_array.push_back(num_bit_array[j]);
			}
		}

		if(zero_bit_array.size() > one_bit_array.size()){
			num_bit_array = one_bit_array;
			lost_number_bit[i] = 1;
		}else if(zero_bit_array.size() < one_bit_array.size()){
			num_bit_array = zero_bit_array;
			lost_number_bit[i] = 0;
		}

		zero_bit_array.clear();
		one_bit_array.clear();
	}

	lost_number = lost_number_bit.to_ulong();

	return true;

}

int main(){

	const std::string file_name("data.txt");
	vector<int> number_array;

	std::cout << "The number array: " << std::endl;

	/*初始化数据*/
	std::ifstream ifs(file_name, ios::in);
	if(ifs.fail()){
		std::cerr << "Sorry, failed to open " << file_name << ". " << std::endl;
		return -1;
	}
	int temp(-1);
	while(ifs >> temp){
		number_array.push_back(temp);
		std::cout << temp << "\t";
	}
	ifs.close();

	std::cout << endl;

	int lost_number(-1);
	find_lost_number(number_array, lost_number);

	std::cout << "The lost number is " << lost_number << ". " << std::endl;

}