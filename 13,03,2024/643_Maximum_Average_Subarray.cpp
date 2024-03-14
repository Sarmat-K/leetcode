#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>

using namespace std;

class solution
{
private:
    vector<int> nums ;
    int k ;
public:
    solution(vector<int>& nums , int n) : nums(nums) , k(n) {}

    double findMaxAverage() {
        if (nums.size() == 1) {
            return nums[0];
        }
        
        double sum_n = 0.0;
        for (int i = 0; i < k; i++) {
            sum_n += nums[i];
        }
        double max_a = sum_n; 
        for (int i = k; i < nums.size(); i++) {
            sum_n += nums[i] - nums[i - k];
            max_a = max(max_a, sum_n);
        }
        
        return max_a/k;
        
    };
};




int main() {
    vector<int> nums = {3,3,4,3,0};
    int n = 3;
    solution solution(nums , n);
    cout << solution.findMaxAverage();

    return 0;
}