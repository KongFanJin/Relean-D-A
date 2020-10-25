// Author: Huahua
class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        deque<int> index;  // 存储的是下标
        vector<int> ans;

        for (int i = 0; i < nums.size(); ++i) {
            // 当队列不空,且当前元素i大于最后插入的元素index.back()
            // 作用:清除队列中小于当前元素的元素
            while (!index.empty() && nums[i] >= nums[index.back()])
                index.pop_back();

            // 入队下标i
            index.push_back(i);

            // 有足够的元素(k个)了
            // 获得index.front()最大元素下标,加入ans中
            if (i - k + 1 >= 0) ans.push_back(nums[index.front()]);

            // 窗口首元素的位置"超过"index.front()了,index.front()不在窗口内了
            if (i - k + 1 >= index.front()) index.pop_front();
        }
        return ans;
    }
};