/**
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
 For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number, and n does not exceed 1690.

**/

#include <set>
#include <cstdint>

class Solution {
public:
    int nthUglyNumber(int n) {
        std::set<uint32_t> uglies = std::set<uint32_t>();
        int initialSize = n * 10;
        int growthRate = 3;
        uglies.insert(1);
        uglies.insert(2);
        uglies.insert(3);
        uglies.insert(5);
        addUglies(uglies,0, initialSize);
        long max = n * 10;
        while(uglies.size() < n){
            addUglies(uglies, max, max * growthRate);
            max *= growthRate;
        }
        std::set<uint32_t>::iterator it = uglies.begin();
        std::advance(it, n - 1);
        return int(*it);
    }
private:
    void addUglies(std::set<uint32_t>& uglies,long checkedUpTo, long max){
        uint32_t factors[3] = {2,3,5};
        long multiple;
        for(std::set<uint32_t>::iterator it = uglies.lower_bound(checkedUpTo / 5); *it <= max / 2; ++it){
            for(int i = 0; i < 3; ++i){
                multiple = long(*it) * factors[i];
                if(multiple <= max) uglies.insert(*it * factors[i]);
            }
        }
    }
};
