/**Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.
Example 1:
Input:

0 0 0
0 1 0
0 0 0
Output:
0 0 0
0 1 0
0 0 0
Example 2:
Input:

0 0 0
0 1 0
1 1 1
Output:
0 0 0
0 1 0
1 2 1
Note:
The number of elements of the given matrix will not exceed 10,000.
There are at least one 0 in the given matrix.
The cells are adjacent in only four directions: up, down, left and right.
**/

/** my solution: using a queue, spread out from the zeroes**/
class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    std::queue<array<int, 2>> q = std::queue<array<int, 2>>();
    std::vector<array<int, 2>> positions;
    array<int, 2> pos;
    for(int i = 0; i < matrix.size(); ++i){
        for(int j = 0; j < matrix[i].size(); ++j){
            if(matrix[i][j] == 0){
                pos = array<int, 2> {i, j};
                q.push(pos);
            }
            else{
              matrix[i][j] = - 1;
            }
        }
    }
    while (!q.empty()){
        pos = q.front();
        positions = adjacentPositions(pos, matrix.size(), matrix[0].size());
        for(vector<array<int, 2>>::iterator it = positions.begin();
                    it != positions.end(); ++it){
            if( matrix[(*it)[0]][(*it)[1]] == - 1 ||
                matrix[(*it)[0]][(*it)[1]] > matrix[pos[0]][pos[1]] + 1){
                matrix[(*it)[0]][(*it)[1]] = matrix[pos[0]][pos[1]] + 1;
                q.push(*it);
            }
        }
        q.pop();
    }
    return matrix;
  }

  inline vector<array<int, 2>> adjacentPositions(array<int, 2>& indices, int rowSize, int colSize){
      vector<array<int, 2>> adjacent = vector<array<int, 2>>();
      array<int,2> newPos;
      int offsets[4][2] = {
          {-1, 0},
          {0, 1},
          {1, 0},
          {0, -1}
      };
      for(int i = 0; i < 4; ++i){
          newPos = array<int, 2>();
          newPos[0] = indices[0] + offsets[i][0];
          newPos[1] = indices[1] + offsets[i][1];
          if(newPos[0] >= 0 && newPos[0] < rowSize &&
             newPos[1] >= 0 && newPos[1] < colSize){
              adjacent.push_back(newPos);
          }
      }
      return adjacent;
  }
};
