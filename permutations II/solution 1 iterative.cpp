/**
 * Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]   
**/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back(nums);
        int currentPerms = 1;
        int temp;
        vector<int> copy;
        unordered_set<int> seen;
        for(int startIdx = 0; startIdx < nums.size() - 1; ++ startIdx){
            currentPerms = result.size();
            for(int permIdx = 0; permIdx < currentPerms; ++ permIdx){
                seen.clear();
                for(int valueIdx = startIdx + 1; valueIdx < nums.size(); ++valueIdx){
                    if(result[permIdx][startIdx] != result[permIdx][valueIdx] && seen.count(result[permIdx][valueIdx]) == 0){
                        copy = result[permIdx];
                        temp  = copy[startIdx];
                        copy[startIdx] = copy[valueIdx];
                        copy[valueIdx] = temp;
                        result.push_back(copy);
                    }
                    seen.insert(result[permIdx][valueIdx]);
                }
            }
        }
        return result;
    }
};