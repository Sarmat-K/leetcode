// Solution for problem 26: Remove Duplicates from Sorted Array
// Difficulty: Easy
// Topics: Arrays

// Your solution code goes here.

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int uniqueIndex = 0; 
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[uniqueIndex]) {
                ++uniqueIndex;
                nums[uniqueIndex] = nums[i]; 
            }
        }
        
        return uniqueIndex + 1; 
    }
};
