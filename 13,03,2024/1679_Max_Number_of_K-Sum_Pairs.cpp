#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class solution
{
private:
    vector<int> nums ;
    int k ;
public:
    solution(vector<int>& nums , int n) : nums(nums) , k(n) {}

    int maxOperations() {
        for (int i = 0 ; i  < nums.size() ; i++) {

            
        }
        
    }
};





int main() {
    vector<int> nums = {1,2,3,4};
    int n = 8;
    solution solution(nums , n);
    cout << solution.maxOperations();

    return 0;
}