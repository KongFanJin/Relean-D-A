#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Author: Huahua
// http://zxi.mytechroad.com/blog/dynamic-programming/leetcode-53-maximum-subarray/
/**
 * 递推关系式/状态转移方程:
 * 
 * f(i) = f(i-1) > 0 ? num[i] + f(i-1) : num[i]
 * 可见最大子序列和不是num[i] + f(i-1) 就是num[i]
 */
class Solution {
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