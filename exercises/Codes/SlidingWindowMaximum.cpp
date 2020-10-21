class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k){
        vector<int> ans{};

        for (auto i = 0; i != nums.size() - k + 1; i++){
            int maxSW = nums[i]; // 默认窗口首元素最大
            for (auto j = i; j != i + k; j++)
                if(nums[j] > maxSW)
                    maxSW = nums[j];

            ans.push_back(maxSW);
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size() == 0) return {};
        vector<int> ans;
        for(int i = 0; i <= nums.size() - k; i ++){
            int maxNum = nums[i];
            for(int j = i; j < i + k; j ++){
                maxNum = max(maxNum, nums[j]);
            }
            ans.push_back(maxNum);
        }
        return ans;
    }
};