
/**
    example
    m = 4,
    n = 4
    1   1   1  1
    1   2   3  4 
    1   3   6  10
    1   4   10 20
    
    This looks like a slice of pascal's triangle
            1
          1   1
         1  2   1
       1  3   3   1
     1  4   6   4   1
   1  5   10  10  5   1
 1  6   15  20  15  6   1
 
 if we want to  the 20 it is row m + n - 2, element n
 
 to get element n = 4, start with el 1 = 1
 next 2 is then 1 * (m+n - 2) / 1 = 6
      3 is      1 * (m+n - 1) / 2 = 15
      4 is      1 * (m+n) / 3     = 20
      
  this will have O(n) time complexity, constant space
**/
class Solution {
public:
    int uniquePaths(int m, int n) {
        long numerator = m + n - 2;
        long denominator = 1;
        long solution = 1;
        if(n > (m + n)/ 2){
            n = m;
        }
        for(int i = 1; i < n; ++i){
            solution = solution * numerator;
            solution = solution / denominator;
            ++denominator;
            --numerator;
        }
        return int(solution);
    }
};