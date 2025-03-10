#include <iostream>
#include <vector>

std::vector<int> sort_v1(std::vector<int> array){
	int c;

	for (int i = 0; i < array.size(); i++){				//O(n^2)  //память 32 бита
		for (int j = i + 1; j < array.size(); j++){
			if (array[j] < array[i]){
				c = array[j];
				array[j] = array[i];
				array[i] = c;			
			}		
		}
	}
	//std::cout << "\n";
	//for (int i: array){
	//	std::cout << i << " ";
	//}
	return array;
}

