class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>items;
        vector<int>sum;
        
        for(int i = 0; i < nums.size(); i++) {
            int curr_target = target - nums[i];
            if(items.count(curr_target)) {
                sum.push_back(i);
                sum.push_back(items[curr_target]);
                return sum;
            }
            else {
                items[nums[i]] = i;
            }
        }
        return {};
    }
};
