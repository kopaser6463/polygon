#include "alg1.cpp"
#include "alg2.cpp"

int main(){
	std::vector<int> a = {2,2,4,6,4,3,6,3,5,7,3,3,5,6,3,5};
	for (int i:a){
		std::cout << i << " ";
	}
	std::cout << "\n";

	std::vector<int> s1 = sort_v1(a);
	std::vector<int> s2 = sort_v2(a);

	for (int i:s1){
		std::cout << i << " ";
	}
	std::cout << "\n";
	for (int i:s2){
		std::cout << i << " ";
	}
}
