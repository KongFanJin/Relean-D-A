#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// LeetCode
// https://leetcode-cn.com/problems/maximum-subarray/solution/hua-jie-suan-fa-53-zui-da-zi-xu-he-by-guanpengchn/
class Solution1 {
   public:
    int maxSubArray(vector<int> nums) {
        int pre = nums[0];
        int sum = nums[0];

        for (auto element : nums) {
            if (sum > 0) { // sum = sum+e,sum可能变大也可能变小,在pre = max(pre, sum)此处判断
                sum += element;
            } else if (sum <= 0) { // 若sum <= 0,即负数+负数,负数+正数,详细分析见exercises\Maximum Subarray.md
                sum = element;
            }

            // max(pre,sum)中的pre是前最大子序列和sum
            // 若sum+e变小,则回退到前最大子序列和sum
            // 若sum+e变大,则取sum
            pre = max(pre, sum); 
        } 

        return pre; // 为什么是pre不是sum?是因为要加入下一个元素(nums[n])时循环退出了
    }
};

// LeetCode
// 上述算法简化,但是难理解
class Solution2 {
   public:
    int maxSubArray(vector<int> nums) {
        auto Max = nums[0];
        auto pre = nums[0];

        for (auto i = 1; i != nums.size(); i++) {
            // pre + nums[i] < nums[i] ,说明nums[i]对pre没有增益,重新选取子序列pre=nums[i]
            // pre + nums[i] > nums[i] ,说明nums[i]对pre有增益
            pre = max(pre + nums[i], nums[i]);
            // Max > pre, 说明pre > pre + nums[i]
            // Max < pre, 说明pre < pre + nums[i], 要回到
            Max = max(Max, pre);
        }

        return Max;
    }
};

// Author: Huahua
// http://zxi.mytechroad.com/blog/dynamic-programming/leetcode-53-maximum-subarray/
/**
 * 递推关系式/状态转移方程:
 * 
 * f(i) = f(i-1) > 0 ? num[i] + f(i-1) : num[i]
 * 
 * 我的理解
 * sum < 0 时, sum = i
 * sum > 0 时, max(sum+i,sum)
 */
class Solution3 {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> f(nums.size());
        f[0] = nums[0];
        
        for (int i = 1; i < nums.size(); ++i)
            // f[i] = f[i-1] > 0 ? f[i-1] + num[i] : num[i]
            f[i] = max(f[i - 1] + nums[i], nums[i]);
        
        return *std::max_element(f.begin(), f.end());
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