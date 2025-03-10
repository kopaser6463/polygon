#include <vector>
class Solution {
public:
	std::vector<int> countBits(int n) {
	std::vector<int> dp(n + 1, 0);      //memory: n+1 * 4 bytes
	int sub = 1;				     //memory: 4 bytes

	for (int i = 1; i <= n; i++) {		     //O(n)
		if (sub * 2 == i) {
			sub = i;
		}

	dp[i] = dp[i - sub] + 1;
	}

	return dp;
    }
};