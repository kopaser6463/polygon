#include "main2.cpp"
#include <iostream>
#include <cassert>

int main(){
	std::vector<std::vector<int>> cost = {{1}};
	Solution s;
	assert(s.generate(1) == cost);	

}
