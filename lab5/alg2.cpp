#include <iostream>
#include <vector>

std::vector<int> sort_v2(std::vector<int> array){
	//for (int i: array){
	//	std::cout << i << " ";
	//}
	//std::cout << "\n";
	if (array.size() == 0){
		return {};
	}
	if (array.size() == 1){
		return {array[0]};
	}
	//std::cout << "inside";
	int num = array[0];
	std::vector<int> a;
	std::vector<int> b;
	for (int i = 1; i < array.size(); i++){
		if (array[i] < num){
			a.push_back(array[i]);
		}
		else{
			b.push_back(array[i]);
		}
	}
	//std::cout << a.size() << " " << b.size();
	std::vector<int> ab;
	ab.reserve(a.size() + 1 + b.size());
	a = sort_v2(a);
	b = sort_v2(b);
	ab = a;
	//ab.insert(ab.end(), a.begin(), a.end());
	ab.push_back(num);
	ab.insert(ab.end(), b.begin(), b.end());
	return ab;
}

