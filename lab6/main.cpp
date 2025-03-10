#include <vector>
class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        int result = 0;                                          //memory: 4 bytes
        std::vector<int> min_cost(cost.size()+1, 0);     //memory: (n+1) * 4 bytes
        for (int i = 2; i < cost.size() + 1; i++){       //O(n+1)
            min_cost[i] = std::min(min_cost[i-2] + cost[i-2],min_cost[i-1] + cost[i-1]);
        }

        return min_cost[cost.size()];
    }
};