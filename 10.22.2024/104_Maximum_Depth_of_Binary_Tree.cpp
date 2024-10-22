// Solution for problem 104: Maximum Depth of Binary Tree
// Difficulty: Easy
// Topics: Tree, Depth-First Search, Breadth-First Search, Binary Tree

// Your solution code goes here.

#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {

        if(root == nullptr) 
            return 0;

        int right_val = maxDepth(root->right);
        int left_val =maxDepth(root->left);
        return max(right_val, left_val) + 1;
        
    }
};