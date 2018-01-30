#include <unordered_set>

class Solution {
    struct pairAndVal{
        pair<int,int> coords;
        int sum;
        pairAndVal(int sum, pair<int, int>coord): sum(sum),
            coords(coords){}
        bool operator<(pairAndVal b){
            return sum < b.sum;
        }
    };

public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_set<pair<int, int>> alreadyVisited;
        priority_queue<pairAndAncestor> minHorizon;
        vector<pair<int, int>> solution;
        minHorizon.push_back(pairAndVal(nums1[0] + nums2[0] pair<int,int>(0,0)));
        pair<int, int> coords;
        while(solution.size() < k){
            coords = minHorizon.top().coords;
            alreadyVisited.push(coords);
            if(coords[1] + 1 < nums2.length && 
               (coords[0] == 0 || alreadyVisited.count(pair<int,int>(coords[0] - 1, coords[1] + 1)) != 0)){       
                minHorizon.push_back(
                    pairAndVal(nums1[coords[0]] + nums2[coords[1] + 1],
                        pair<int,int>(coords[0], coords[1]+1)
                    )
                );
            }
            if(coords[0] + 1 < nums1.length && (coords[1] == 0 || alreadyVisited.count(pair<int,int>(coords[0] + 1, coords[1] - 1) != 0 ))){ 
                minHorizon.push_back(
                    pairAndVal(nums1[coords[0] + 1] + nums2[coords[1]],
                        pair<int,int>(coords[0] + 1, coords[1])
                    )
                );
            }
        }
        return solution;    
    }
};