class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> table;
        

        for(int i = 0; i < nums.size(); i++){
            int temp = target - nums[i];

            if(table.find(temp) != table.end()){
                return {table[temp], i};
            }
            table[nums[i]] = i;
        }

        return{};
    }
};