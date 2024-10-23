#include <iostream> 
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> duplicate;
        for(int num : nums){
            if(duplicate.find(num) != duplicate.end()){
                return true;
            }
            duplicate.insert(num);
        }
        return false;
    }
};

int main(){
    Solution ans;

    std::vector<int> val = {1, 2, 3, 1};

    std::cout << std::boolalpha << ans.containsDuplicate(val);
    return 0;
}
