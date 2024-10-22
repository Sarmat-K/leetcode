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
    int goal ;
public:
    solution(vector<int>& nums , int n) : nums(nums) , goal(n) {}

    int help(int x,vector<int>& nums){
        if(x < 0) return 0;

        int res = 0;
        int l = 0 , cur = 0;

        for (int i = 0; i < nums.size(); i++){
            cur += nums[i];
            while( cur > x){
                cur -= nums[l];
                l+=1;
            }
            res += (i-l+1);
        }
        return res;

    }
    
    int numSubarraysWithSum() {
        //  Мое решение - Limit time
        // int sum = 0 , count_sub = 0, next = 0, i = 0;
        // for (int num : nums) {
        //     sum = 0;
        //     cout << i << " " << next << "-" << nums[i]<< "    :" ;
        //     i = i + next;
        //     while (sum <= goal)
        //     {
        //         sum += nums[i+ next];
        //         if (sum == goal)
        //             count_sub+= i+1;
        //         cout << nums[i+ next] <<":" << sum << "   ";
        //         i++;
        //     }
        //     i = 0 ;
        //     next++;
        //     cout << endl ;
        // }


        return help(goal,nums) - help(goal-1, nums);
    }
};





int main() {
    vector<int> nums = {1,0,1,0,1};
    int n = 2;
    solution solution(nums , n);
    cout << solution.numSubarraysWithSum();

    return 0;
}