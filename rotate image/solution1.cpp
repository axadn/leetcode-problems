/**
 You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
Example 2:

Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
**/

//my in-place solution
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int maxRadius = (matrix.size() - 1) /2;
        int temp1;
        int temp2;
        for(int radius = maxRadius; radius >= 0; --radius){
            for(int element = maxRadius - radius; element < matrix.size() - 1 - (maxRadius - radius); ++element){
                temp1 = getElement(radius, 3, element, matrix);
                for(int side = 0; side < 4; ++side){
                    temp2 = getElement(radius, side, element, matrix);
                    setElement(radius, side, element, temp1, matrix);
                    temp1 = temp2;
                }
            }
        }
    }
    
    inline vector<int> getRowCol(int radius, int sideIdx, int elementIdx, vector<vector<int>>& matrix){
        int rowNumber, columnNumber;
        switch(sideIdx){
            case 0: 
                rowNumber = (matrix.size() - 1) / 2  - radius;
                columnNumber = elementIdx;
                break;
            case 1:
                rowNumber = elementIdx;
                columnNumber = (matrix.size()) / 2 + radius;
                break;
            case 2:
                rowNumber = matrix.size() / 2  + radius;
                columnNumber = matrix.size() - 1 - elementIdx;
                break;
            case 3:
                rowNumber = matrix.size() - 1 - elementIdx;
                columnNumber = (matrix.size() - 1) /2 - radius;
        }
        return vector<int>({rowNumber, columnNumber});
    }
    inline void setElement(int radius, int sideIdx, int elementIdx, int value, vector<vector<int>>& matrix){
        vector<int> rowCol = getRowCol(radius, sideIdx, elementIdx, matrix); 
        matrix[rowCol[0]][rowCol[1]] = value;
    }
    inline int getElement(int radius, int sideIdx, int elementIdx, vector<vector<int>>& matrix){
        vector<int> rowCol = getRowCol(radius, sideIdx, elementIdx, matrix); 
        return matrix[rowCol[0]][rowCol[1]];
    }
};