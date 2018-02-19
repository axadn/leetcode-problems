/**
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
**/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int searchStart = 0;
        int searchEnd = nums.size() - 1;
        // search for start
        int rangeStart = -1;
        int rangeEnd = -1 ;
        int middle;
        while(rangeStart == -1 && searchStart <= searchEnd){
            middle = (searchStart + searchEnd) / 2;
            cout << middle << "\n";
            if(nums[middle] == target){
                if(middle == 0 || nums[middle - 1] != target){
                    rangeStart = middle;
                }
                else{
                    searchEnd = middle - 1;
                }
            }
            else if(nums[middle] > target){
                searchEnd = middle - 1;
            }
            else{
                searchStart = middle + 1;
            }
        }
        // search for end
        searchStart = 0;
        searchEnd = nums.size() - 1;
        while(rangeEnd == -1 && searchStart <= searchEnd){
            middle = (searchStart + searchEnd) / 2;
            if(nums[middle] == target){
                if(middle == nums.size() - 1 || nums[middle + 1] != target){
                    rangeEnd = middle;
                }
                else{
                    searchStart = middle + 1;
                }
            }
            else if(nums[middle] < target){
                searchStart = middle + 1;
            }
            else{
                searchEnd = middle - 1;
            }
        }
        vector<int> solution;
        solution.push_back(rangeStart);
        solution.push_back(rangeEnd);
        return solution;
    }
    
};