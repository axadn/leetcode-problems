/**
Given n non-negative integers representing an elevation map where the width of each bar is 1,
 compute how much water it is able to trap after raining.

For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
** My pseudocode

keep track of total water in variable

loop from end:
    compute right max of previous position

loop from start:
    compute left max of previous position

final loop :
    add (min(right max, left max) - height) to total water

**/


class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() < 3) return 0;
        vector<int> maxes((height.size() - 2) * 2);

        int max = 0;
        for(int i = 0; i < height.size() - 2; ++i){
            max = std::max(max, height[i]);
            maxes[(i) * 2] = max;
        }
        max = 0;
        for(int i = height.size() - 2; i >= 1; --i){
            max = std::max(max, height[i + 1]);
            maxes[(i-1) * 2 + 1] = max;
        }
        int total = 0;
        int minBound;
        for(int i = 0; i < height.size() - 2; ++ i){
            minBound = min(maxes[i*2], maxes[i*2 + 1]);
            if(height[i + 1] < minBound){
                total +=  minBound - height[i + 1];
            }
        }
        return total;
    }
};
