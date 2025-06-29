/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* build(vector<vector<int>>& grid, int row, int col, int size) {
        if(size==1) return new Node(grid[row][col],true);
        int half=size/2;
        Node* topLeft=build(grid,row,col,half);
        Node* topRight=build(grid,row,col+half,half);
        Node* bottomLeft=build(grid,row+half,col,half);
        Node* bottomRight=build(grid,row+half,col+half,half);

        if(topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf &&
            topLeft->val == topRight->val && topRight->val == bottomLeft->val && bottomLeft->val == bottomRight->val){
            return new Node(topLeft->val,true);
        }

        return new Node(true,false,topLeft,topRight,bottomLeft,bottomRight);
    }

    Node* construct(vector<vector<int>>& grid) { 
        return build(grid,0,0,grid.size());
    }
};