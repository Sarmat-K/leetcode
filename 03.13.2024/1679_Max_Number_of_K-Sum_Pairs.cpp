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

    int maxOperations() {
        // Мое решение Limit time - error
        // int count = 0;
        // for (int i = 0 ; i  < nums.size() ; i++) {
        //     auto it = find(nums.begin(), nums.end(), k-nums[i]);
        //     if (it != nums.end() && it != nums.begin() + i){
        //         if(it > nums.begin()+i){
        //             nums.erase(it);
        //             nums.erase(nums.begin() + i);
        //             i--;
        //         }else {
        //             nums.erase(nums.begin() + i);
        //             nums.erase(it);
        //             i--;
        //         }
        //         count++;
        //     }
        // }
        // return count;
    //_____________________________________________________________
        // GPT - hash table : memory - error
        // std::unordered_map<int, int> map;
        // int count = 0;
        // for (int num : nums) {
        //     int complement = k - num;
        //     if (map[complement] > 0) {
        //         count++;
        //         map[complement]--;
        //     } else {
        //         map[num]++;
        //     }
        // }
        // return count;
    //_____________________________________________________________
        // correct code with two pointers 
        sort(nums.begin(), nums.end());
        int l_i = 0 , r_i =nums.size() - 1 , count = 0;

        while (l_i < r_i){
            int temp = nums[l_i] + nums[r_i];
            if (temp == k) count++ , l_i++ , r_i--;
            else if (temp < k) l_i++;
            else r_i--;
        }
        return count;
    }
};





int main() {
    vector<int> nums = {3,1,3,4,3};
    int n = 6;
    solution solution(nums , n);
    cout << solution.maxOperations();

    return 0;
}