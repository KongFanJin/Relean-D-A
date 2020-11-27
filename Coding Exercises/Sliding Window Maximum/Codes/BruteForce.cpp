// Author: Huahua

/*
  max_element https://docs.microsoft.com/zh-cn/cpp/standard-library/algorithm-functions?view=vs-2019#max_element
  Finds the first occurrence of largest element in a specified range where the ordering criterion may be specified by a binary predicate.
*/

// 超出时间限制	N/A	N/A	C++
// 时间复杂度分析: O((n-k+1)k)

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {    
    vector<int> ans;
    
    for (int i = 0; i != (nums.size()-k)+1; ++i) { // n-k+1
      ans.push_back(*max_element(nums.begin() + i, nums.begin() + i + k));
    }
      
    return ans;
  }
};