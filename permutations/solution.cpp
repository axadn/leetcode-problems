class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        return permuteStep(nums, 0);
    }
    vector<vector<int>> permuteStep(vector<int>& nums, int startIdx){
        vector<vector<int>> permutations;
        vector<int> permutation;
        if(startIdx + 1 >= nums.size()){
            permutations.push_back(nums);
        }
        else{
            vector<vector<int>> newPermutations;
            vector<int> numsCopy;
            int temp;
            newPermutations = permuteStep(nums, startIdx + 1);
            for(auto it = newPermutations.begin(); it != newPermutations.end(); ++it){
                permutations.push_back(*it);
            }
            for(int i = startIdx + 1; i < nums.size(); ++i){
                numsCopy = nums;
                numsCopy[startIdx] = numsCopy[i];
                numsCopy[i] = nums[startIdx];
                newPermutations = permuteStep(numsCopy, startIdx + 1);
                for(auto it = newPermutations.begin(); it != newPermutations.end(); ++it){
                    permutations.push_back(*it);
                }
            }
        }
        return permutations;
    }
};