class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int upper = std::upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        int lower = std::lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        vector<int> range;
        if(nums.size() == 0 || upper == - 1 || nums[upper] != target){
            range.push_back(-1);
            range.push_back(-1);
        }
        else{
            range.push_back(lower);
            range.push_back(upper);
        }
        return range;   
    }
};