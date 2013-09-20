/*From Programming Perls, By C.L.Wang*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){

	std::vector<int> array_data;
	int search_data(0);

	/*initialize the array*/
	int temp;
	std::cout << "Please input the data (non-integer is end): " << std::endl;
	while(std::cin >> temp){
		array_data.push_back(temp);
	}
	std::sort(array_data.begin(), array_data.end());
	std::cout << "The ordered array: " << std::endl;
	for(unsigned int i=0; i<array_data.size(); i++){
		std::cout << array_data[i] << "\t";
	}

	std::cin.clear();/*necessary to cin*/
	std::cin.sync();

	std::cout << std::endl;
	std::cout << "Please input the finding data:" << std::endl;
	std::cin >> search_data;

	/*binary search*/
	unsigned int n = array_data.size();
	int low(0), high(n-1), mid(0);
	while(low<=high){
		mid=(low+high)/2;
		if(array_data[mid] == search_data) 
			break;
		if(array_data[mid] > search_data)
			high=mid-1;
		else
			low=mid+1;
	}

	/*output result*/
	if(mid != 0){
		std::cout << "Thanks, the data " << search_data << " is in the "
			<< mid+1 << " position of the array. " << std::endl;
	}else{
		std::cout << "Sorry, the data " << search_data 
			<< " is not in the array. " << std::endl;
	}

	return 0;

}