// Solution for problem 659: Split array in to consecutive subsequences
// Difficulty: mideum
// Topics: Array, Hash Table, Greedy, Heap (Priority Queue)

// Your solution code goes here.

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;


bool isPossible(vector<int>& nums) {
    unordered_map<int, int> freq;
    unordered_map<int, int> need;

    for(const int& num: nums){
        freq[num]++;
    }

    for(const int& num: nums){
        if(freq[num] == 0) continue ;

        if(need[num] > 0){
            need[num]--;
            need[num + 1]++;
        } else if(freq[num + 1] > 0 && freq[num + 2] > 0){
            freq[num + 1]--;
            freq[num + 2]--;
            need[num + 3]--;
        } else {
            return false;
        }

        freq[num]--;
    }

    return true;

}


int main(){
    vector<int> nums = {1,2,3,4,4,5};

    cout << isPossible(nums)<< endl;

    return 0;
}