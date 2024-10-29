// Solution for problem 27 : Remove Element
// Difficulty: Easy
// Topics: array

// Your solution code goes here.

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) k++;
            else swap(nums[i], nums[i-k]);
        }
        return nums.size()-k;
    }
};