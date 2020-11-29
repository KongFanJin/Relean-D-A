#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// LeetCode
// https://leetcode-cn.com/problems/maximum-subarray/solution/hua-jie-suan-fa-53-zui-da-zi-xu-he-by-guanpengchn/
// 详细分析见exercises\Maximum Subarray.md
class Solution1 {
   public:
    int maxSubArray(vector<int> nums) {
        int pre = nums[0];
        int sum = nums[0];

        for (auto element : nums) {
            if (sum > 0) {
                sum += element;
            } else if (sum <= 0) {
                sum = element;
            }

            pre = max(pre, sum); 
        } 

        return pre;
    }
};

// LeetCode
// 对比斐波那契数列的迭代形式
class Solution2{
   public:
    int maxSubArray(vector<int> nums) {
        auto sum = nums[0];
        auto next = nums[0];

        for (auto i = 1; i != nums.size(); i++) {
            next = max(next + nums[i], nums[i]);
            sum = max(sum, next);
        }

        return sum;
    }
};

class Solution3{
   public:
	int maxSubArray(vector<int>& nums) {
		vector<int> dp(nums.size());
		dp[0] = nums[0];
		int Max = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			dp[i] = max(dp[i-1] + nums[i], nums[i]);	
			if (Max < dp[i]) {
				Max = dp[i];
			}
		}

		return Max;
	}
};

// Author: Huahua
// http://zxi.mytechroad.com/blog/dynamic-programming/leetcode-53-maximum-subarray/
/**
 * 以num[i]为主来考虑(注num[i]+f(i-1)),而不是f(i-1)(注f(i-1)+num[i]),
 * num[i]+正数变大,num[i]+负数变小
 * 
 * 得递推关系式/状态转移方程: 
 * f(i) = f(i-1) > 0 ? num[i] + f(i-1) : num[i]
 * 
 * 模拟运行
 * nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
 * f    = [-2, 1, -2, 4,  3, 5, 6,  1, 5]
 * 
 * 思维转换
 * f[i] = max(nums[i] + f[i - 1], nums[i]) 与 f(i) = f(i-1) > 0 ? num[i] + f(i-1) : num[i]等价
 * 若nums[i] + f[i - 1] > nums[i],即f(i-1) > 0, f(i) = num[i] + f(i-1)
 * 若nums[i] + f[i - 1] < nums[i],即f(i-1) < 0, f(i) = num[i]
 */
class Solution4 {
public:
    int maxSubArray(vector<int>& nums) {
        // 存储当前`nums[0:i]`的连续子序列最大和
        vector<int> f(nums.size()); 
        f[0] = nums[0];
        
        for (int i = 1; i < nums.size(); ++i)
            f[i] = max(nums[i] + f[i - 1], nums[i]);
        
        return *std::max_element(f.begin(), f.end());
    }
};


// Solution4的改进,使用O(1)的空间复杂度
class Solution4X {
public:
    int maxSubArray(vector<int>& nums) {
        auto ans = nums[0];
        auto sum = nums[0];    
        for (int i = 1; i < nums.size(); ++i){
            sum =  max(nums[i] + sum, nums[i]);
            if(sum > ans) ans = sum;
        }

        return ans;
    }
};


int main() {
    Solution4 sol;
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << "nums: ";
    for (auto i : nums) cout << i << " ";
    cout << "\n";

    cout << "maxSubArray: " << sol.maxSubArray(nums);
}