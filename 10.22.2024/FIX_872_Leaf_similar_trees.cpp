// Solution for problem 872: Leaf_similar trees
// Difficulty: Easy
// Topics: Tree, Depth_first serch, Binary Tree

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

    void get_val(TreeNode* root, vector<int>& val){
        if(root == nullptr)
            return;
        
        if(root->left == nullptr && root->right == nullptr){
            val.push_back(root->val);
        }
        get_val(root->right, val);
        get_val(root->left, val);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> val_root1 , val_root2;

        get_val(root1, val_root1);
        get_val(root2, val_root2);

        return val_root1 == val_root2;

    }
};
