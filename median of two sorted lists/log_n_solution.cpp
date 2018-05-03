/**
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5 
**/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() == 0 && nums2.size() == 0) return 0;
        vector<int> * longer, * shorter;
        if(nums1.size() < nums2.size()){
            shorter = &nums1;
            longer = &nums2;
        }else{
            shorter = &nums2;
            longer = &nums1;
        }
        vector<int> partitions = findPartitions(*shorter, *longer, 0, shorter->size());
        
        if((shorter->size() + longer->size()) % 2 == 0){   // we need to average two numbers
            double median1, median2;
            if(partitions[0] == shorter->size()){
                median1 = double((*longer)[partitions[1]]);
                median2 = double((*longer)[partitions[1] - 1]);
                if(shorter->size() > 0){
                    median2 = max(median2, double((*shorter)[shorter->size() - 1]));
                }
            }else if(partitions[1] == longer->size()){
                median1 = double((*shorter)[partitions[0]]);
                median2 = double((*shorter)[partitions[0] - 1]);
                if(longer->size() > 0){
                    median2 = max(median2, double((*longer)[longer->size() - 1]));
                }
            }else{
                median1 = double((*shorter)[partitions[0]]);
                median1 = min(median1, double((*longer)[partitions[1]]));
                
                if(partitions[0] > 0 && partitions[1] > 0){
                    median2 = max(double((*shorter)[partitions[0] - 1]), double((*longer)[partitions[1] - 1]));
                } else if (partitions[0] > 0 ){
                    median2 = double((*shorter)[partitions[0] - 1]);
                } else{
                    median2 = double((*longer)[partitions[1] - 1]);
                }
                
            }
            return (median1 + median2) / 2;
        }else{ // there is only one median
            int median;
            if(partitions[0] == shorter->size()){
                median = (*longer)[partitions[1] - 1];
                if(shorter->size() > 0){
                    median = max(median, (*shorter)[shorter->size() - 1]);
                }
            }
            else if(partitions[1] == longer->size()){
                median = (*shorter)[partitions[0] - 1];
                if(longer->size() > 0){
                    median = max(median, (*longer)[longer->size() - 1]);
                }
            }
            else return max((*longer)[partitions[1] - 1], (*shorter)[partitions[0] - 1]);
            return median;
        }
        return 0;
    }
    vector<int> findPartitions(vector<int>& shorter, vector<int>& longer,
                   int shorterStart, int shorterEnd){
        int mid = (shorterStart + shorterEnd + 1) / 2;
        int longerMid = (shorter.size() + longer.size() + 1) / 2 - mid;
        if(mid > 0 && longerMid < longer.size() && shorter[mid - 1] > longer[longerMid]){
            return findPartitions(shorter, longer, shorterStart, mid - 1);
        }else if (longerMid > 0 && mid < shorter.size() && longer[longerMid - 1] > shorter[mid]){
            return findPartitions(shorter, longer, mid + 1, shorterEnd);
        }
        else return vector<int>( {mid, longerMid});
    }
};