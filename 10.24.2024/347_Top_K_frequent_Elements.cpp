// Solution for problem 347: Top K frequent Elements
// Difficulty: Medium
// Topics: Array, Hash Table, Divide and Conquer, Sorting, Heap (Priority Queue), Bucket Sort, Counting, Quickselect

// Your solution code goes here.

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int , int> freq_num;
    for(int num : nums){
        freq_num[num]++;
    }

    priority_queue<pair<int,int>> pq;
    for(const auto& comb : freq_num){
        pq.push({comb.second, comb.first});
    }
    
    vector<int> ans;
    for(int i = 0; i < k ; i++){
        ans.push_back(pq.top().second);
        pq.pop();
    }

    return ans;
}


int main(){
    vector<int> nums = {1,1,1,2,3,2};
    int k = 2;

    vector<int> ans = topKFrequent(nums, k);

    for(int num : ans){
        cout << num << endl;
    }
    
    return 0;
}