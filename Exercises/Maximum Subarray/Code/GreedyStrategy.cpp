#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// LeetCode
// https://leetcode-cn.com/problems/maximum-subarray/solution/hua-jie-suan-fa-53-zui-da-zi-xu-he-by-guanpengchn/
class Solution {
   public:
    int maxSubArray(vector<int> nums) {
        int pre = nums[0];
        int sum = nums[0];

        for (auto e : nums) {
            if (sum > 0) { // 若sum+e,sum可能变大也可能变小
                sum += e;
            } else if (sum <= 0) { // 若sum <= 0,则负数+负数变小,负数+正数还是变小,即sum + e < e
                sum = e;
            }

            // max(pre,sum)中的pre是未加e的最大子序列和sum
            // 若sum+e变小,则回退到sum
            pre = max(pre, sum); 
        } 

        return pre; // 为什么是pre不是sum?是因为要加入下一个元素(nums[n])时循环退出吗?
    }
};

// LeetCode
// 上述算法简化,但是难理解
class Solution {
   public:
    int maxSubArray(vector<int> nums) {
        auto Max = nums[0];
        auto pre = nums[0];

        for (auto i = 1; i != nums.size(); i++) {
            // pre + nums[i] < num[i] ,说明num[i]对pre没有增益,即 pre < 0 或 num[i] < 0 且 pre > 0
            // pre + nums[i] > num[i] ,说明num[i]对pre有增益,即 pre > 0 且 num[i] > 0
            pre = max(pre + nums[i], nums[i]);
            Max = max(Max, pre);
        }

        return Max;
    }
};

int main() {
    Solution sol;
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << "nums: ";
    for (auto i : nums) cout << i << " ";
    cout << "\n";

    cout << "maxSubArray: " << sol.maxSubArray(nums);
}