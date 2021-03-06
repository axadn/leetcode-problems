/**
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u,v) which consists of one element from the first array and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

Example 1:
Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3

Return: [1,2],[1,4],[1,6]

The first 3 pairs are returned from the sequence:
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:
Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2

Return: [1,1],[1,1]

The first 2 pairs are returned from the sequence:
[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
Example 3:
Given nums1 = [1,2], nums2 = [3],  k = 3 

Return: [1,3],[2,3]

All possible pairs are returned from the sequence:
[1,3],[2,3]
Credits:
Special thanks to @elmirap and @StefanPochmann for adding this problem and creating all test cases.
**/


//optimized solution using a priority queue
struct pairAndVal{
        pair<int,int> coords;
        int sum;
        pairAndVal(int sum, pair<int, int> coords): sum(sum),
            coords(coords){}
        bool operator<(const pairAndVal& b) const {
            if(sum == b.sum){
                if(coords.first < b.coords.first){
                    return true;
                }
                return false;
            }
            return sum > b.sum;
        }    
};
class Solution {

public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        vector<int> rowMax(nums2.size(), -1);
        vector<int> colMax(nums1.size(), -1);
        priority_queue<pairAndVal> minHorizon;
        vector<pair<int, int>> solution;
        if(nums1.size() == 0 || nums2.size() == 0) return solution;
        minHorizon.push(pairAndVal(nums1[0] + nums2[0], pair<int,int>(0,0)));
        pair<int, int> coords;
        while(solution.size() < k && minHorizon.size() > 0){
            coords = minHorizon.top().coords;
            minHorizon.pop();
            solution.push_back(pair<int,int>(nums1[coords.first], nums2[coords.second]));
            if(coords.second + 1 < nums2.size() && 
                (coords.first == 0 || rowMax[coords.second + 1] == coords.first - 1)
            ){       
                minHorizon.push(
                    pairAndVal(nums1[coords.first] + nums2[coords.second + 1],
                        pair<int,int>(coords.first, coords.second+1)
                    )
                );
                colMax[coords.first] += 1;
                rowMax[coords.second + 1] += 1;
            }
            if(coords.first + 1 < nums1.size() && 
                (coords.second == 0 || colMax[coords.first + 1] == coords.second - 1 )
            ){ 
                minHorizon.push(
                    pairAndVal(nums1[coords.first + 1] + nums2[coords.second],
                        pair<int,int>(coords.first + 1, coords.second)
                    )
                );
                rowMax[coords.second] += 1;
                colMax[coords.first + 1] += 1;
            }
        }
        return solution;    
    }
};
