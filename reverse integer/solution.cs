/**Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output:  321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only hold integers within the 32-bit signed integer range. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

using System.Collections.Generic;
public class Solution {
    public int Reverse(int x) {
        int numDigits;
        int sum = 0;
        int addValue;
        double addValueD;
        bool negative = x < 0;
        if(negative) x *= -1;

        Stack<int> stack = new Stack<int>();
        while( x > 0){
            stack.Push(x % 10);
            x /= 10;
        }
        numDigits = stack.Count;
        while (stack.Count > 0 ){
            //Console.WriteLine(stack.Peek() * (int)Math.Pow(10, numDigits - stack.Count - 1));
            addValueD = stack.Pop() * Math.Pow(10, numDigits - stack.Count -1 );
            if(addValueD > 2147483647 ) return 0;
            addValue = (int)addValueD;
            if(addValue < 0 || addValue > 2147483647 || addValue > 2147483647 - sum){
                return 0;
            }
            sum += addValue;

        }

        if(negative){
            sum *= -1;
        }
        return sum;
    }
}
