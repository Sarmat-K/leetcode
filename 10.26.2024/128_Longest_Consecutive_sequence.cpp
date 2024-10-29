// Solution for problem 128: Longest Consecutive sequence
// Difficulty: Mideum
// Topics: Array, Hash table, Union Find

// Your solution code goes here.

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;


int longestConsecutive(vector<int>& nums) {
    unordered_set<int> store(nums.begin(), nums.end());
    int res = 0;

    for(const int& num : nums){
        int streak = 0;
        int curr = num;

        while(store.find(curr) != store.end()){
            streak++;
            curr++;
        }

        res = max(res, streak);
    }

    return res;
}

int main(){
    vector<int> nums = {4, 100, 2, 3, 1 ,200};

    int streak = longestConsecutive(nums);
    cout << streak << endl;

    return 0;
}