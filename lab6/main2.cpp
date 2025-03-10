#include <vector>
class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {  //O(n^2)
        std::vector<std::vector<int>> output;                         //memory: ((n+1)*n)/2 * 4 bytes
        for(int i = 0; i < numRows; i++){                              //O(n)
            std::vector<int> temp(i + 1, 1);			      //memory max: n * 4 bytes
            for (int ii = 1; ii < i; ii++){                                     //O(n)
                temp[ii] = output[i - 1][ii - 1] + output[i - 1][ii];
            }
            output.push_back(temp);				      //O(1)
        }
        return output;
    }
};