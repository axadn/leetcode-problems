/**
Given a string containing just the characters '(' and ')',
 find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()",
 which has length = 4.

**/
const int LEFT = 0;
const int RIGHT = -1;

class Solution {
public:
    int longestValidParentheses(string s) {
        int max = 0;
        stack<int> stack;
        int val;
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == '('){
                stack.push(LEFT);
            }
            else{
                if(stack.empty()){
                    stack.push(RIGHT);
                }
                else if (stack.top() == LEFT){
                    handleLeft(stack);
                }
                else if (stack.top() != RIGHT){
                    handleValues(stack);
                }
            }
        }
        while(!stack.empty()){
            if (stack.top() > max) max = stack.top();
            stack.pop();
        }
        return max * 2;
    }
    inline void handleLeft(stack<int>& stack){
        stack.pop();
        addVal(stack, 1);

    }
    inline void addVal(stack<int>& stack,int value){
        if(stack.empty()|| stack.top() == LEFT || stack.top() == RIGHT){
            stack.push(value);
        }
        else{
            int val = value;
            while(!(stack.empty() || stack.top() ==LEFT || stack.top() == RIGHT)){
                val += stack.top();
                stack.pop();
            }
            stack.push(val);
        }
    }
    inline void handleValues(stack<int>& stack){
        int val = stack.top();
        stack.pop();
        if(!stack.empty() && stack.top() == LEFT){
            stack.pop();
            addVal(stack, 1 + val);
        }
        else{
            stack.push(val);
            stack.push(RIGHT);
        }
    }
};
