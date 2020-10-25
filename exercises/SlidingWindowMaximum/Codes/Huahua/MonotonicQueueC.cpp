// Author: Huahua
// 通过	444 ms 104.4 MB C++
// 时间复杂度分析:
class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;

        for (int i = 0; i < nums.size(); ++i) {
            // 当队列不空,且当前元素大于最后插入的元素q.back()
            // 作用:清除队列中小于当前元素的元素
            while (!q.empty() && nums[i] > q.back()) q.pop_back();

            // 入队nums[i]
            q.push_back(nums[i]);

            const int s = i - k + 1;

            // 窗口元素不足k个
            // 跳出本次循环,以便继续加入元素
            if (s < 0) continue;

            ans.push_back(q.front());  // 获得q.front(),加入ans中

            // 同 MonotonicQueueA
            // 若不等则nums[i - (k - 1)]一定小于q.pop_front(),然后在push_back就会被pop_back
            // 若相等,需要滑动窗口时,nums[i - (k - 1)]也需要被pop_front
            if (nums[s] == q.front()) q.pop_front();
        }
        return ans;
    }
};