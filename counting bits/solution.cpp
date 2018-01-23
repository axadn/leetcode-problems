/**
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
Credits:
Special thanks to @ syedee for adding this problem and creating all test cases.

**/

/** my O(n) (like a boss ?) solution in one pass: 
 * */

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> counts;
        counts.push_back(0);
        if(num == 0) return counts;
        int backTraceCount = 1;
        int batchStart = 1;
        while(counts.size() < num + 1){
            for(int i = 0; i < backTraceCount; ++i){
                counts.push_back(1 + counts[batchStart - backTraceCount + i]);
                if(counts.size() == num + 1) return counts;
            }
            backTraceCount *= 2;
            batchStart = counts.size();
        }
        return counts;
    }
};