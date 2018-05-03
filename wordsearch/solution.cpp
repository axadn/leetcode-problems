/**Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
**/

/** my solution: depth-first search using the call-stack
 * **/

class Solution {
public:
    
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>>used;
        for(int i = 0; i < board.size(); ++i){
            used.push_back(vector<bool>(board[0].size(), false));
        }
        for(int i = 0; i < board.size(); ++i){
            for(int j =0; j < board[0].size(); ++j){
                if(board[i][j] == word[0] && existHelper(board, used, vector<int>{i,j}, word, 0)) return true;
            }
        }
        return false;
    }
    vector<vector<int>> getAdjacentPositions(vector<int>& position, vector<vector<char>>& board){
        vector<vector<int>> positions;
        if(position[0] > 0){
            positions.push_back(vector<int>{position[0] - 1, position[1]});
        }
        if(position[1] > 0){
            positions.push_back(vector<int>{position[0], position[1] - 1});
        }
        if(position[0] < board.size() - 1){
            positions.push_back(vector<int>{position[0] + 1, position[1]});
        }
        if(position[1] < board[0].size() - 1){
            positions.push_back(vector<int>{position[0], position[1] + 1});
        }
        return positions;
    }
    bool existHelper(vector<vector<char>>& board,
                     vector<vector<bool>>& used,
                     vector<int> position, string word, int stringIdx){
        if(stringIdx == word.size() - 1) return true;
        vector<vector<int>> adjacentPositions = getAdjacentPositions(position, board);
        
        used[position[0]][position[1]] = true;
        for(int i = 0; i < adjacentPositions.size(); ++i){
            if(
                !used[adjacentPositions[i][0]][adjacentPositions[i][1]] &&
                board[adjacentPositions[i][0]][adjacentPositions[i][1]] == word[stringIdx + 1]
            ){
                if(existHelper(board, used, vector<int>{adjacentPositions[i][0], adjacentPositions[i][1]}, word,
                               stringIdx + 1)) return true;
            }
        }
        used[position[0]][position[1]] = false;
        return false;
    }
    
    
};