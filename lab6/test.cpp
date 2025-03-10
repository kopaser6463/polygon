#include "main.cpp"
#include <iostream>
#include <cassert>

int main(){
	std::vector<int> cost = {10,15,20};
	Solution s;
	assert(s.minCostClimbingStairs(cost) == 15);	
	std::cout << s.minCostClimbingStairs(cost);
}
