// Solution for problem 238: Product of array except self
// Difficulty: Medium
// Topics: Array, Prefix sum

// Your solution code goes here.

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> ans (nums.size() , 1);

    for(int i = 1 ; i < nums.size(); i++){
        ans[i] = ans[i-1] * nums[i -1];
    }

    int temp = 1;
    for(int i = nums.size() -1 ; i >= 0; i--){
        ans[i] *= temp;
        temp *= nums[i];
    }

    return ans;
}

int main(){
    vector<int> nums = { 1,2,3,4};

    vector<int> chek = productExceptSelf(nums);

    for(const int& num : chek){
        cout << num << ' ';
    }
    cout << endl;
    return 0;
}
