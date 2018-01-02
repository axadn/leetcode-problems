/**
Find all possible combinations of k numbers that add up to a number n,
 given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]
**/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        return combinationSumStep(k, n, 0);
    }
private:
    vector<vector<int>> combinationSumStep(int k, int n, int lastUsed){
        vector<vector<int>> sets = *new vector<vector<int>>();
        if(k == 1){
            if(lastUsed < n && n<= 9 ){
                vector<int> set = *new vector<int>();
                set.push_back(n);
                sets.push_back(set);
            }
            return sets;
        }
        vector<vector<int>> subSolutions;
        vector<vector<int>>::iterator subSolutionPtr;
        for(int i = lastUsed + 1; i <= 9 - (k-1) && i < n; ++i){
            subSolutions = combinationSumStep(k - 1, n - i, i);
            if(i == 1)std::cout << subSolutions.size();
            for(subSolutionPtr = subSolutions.begin(); subSolutionPtr < subSolutions.end(); subSolutionPtr++){
                subSolutionPtr->insert(subSolutionPtr->begin(),i);
                sets.push_back(*subSolutionPtr);
            }
        }
        return sets;
    }
};
