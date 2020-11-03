// Author: Huahua

/*
  multiset https://zh.cppreference.com/w/cpp/container/multiset

  multiset::rbegin()
  Returns a const iterator addressing the first element in a reversed multiset.

  multiset::equal_range()
  含一对定义所需范围的迭代器的 std::pair ：第一个指向首个不小于 key
  的元素，第二个指向首个大于 key 的元素。 若无元素不小于 key ，则将尾后（见
  end() ）迭代器作为第一元素返回。 类似地，若无元素大于 key
  ，则将尾后迭代器作为第二元素返回。

  multiset::void erase( iterator pos )
  删除迭代器指向的元素
*/

// 通过 1284 ms 162.7 MB C++
// 时间复杂度分析:红黑树排序O(nlogn)

class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> ans;

        if (nums.empty()) return ans;

        // 将[0,0+k-1)的k-1个元素加入到multiset中
        multiset<int> window(nums.begin(), nums.begin() + k - 1);
        for (int i = k - 1; i < nums.size(); ++i) {
            window.insert(nums[i]);  // 插入,此时窗口有k个元素

            // if (i - k + 1 >= 0) { //窗口有k个元素时,考虑找出窗口的最大值

            // multiset默认递增序列;获得最大值,存入ans
            ans.push_back(*window.rbegin());

            // 创建完集合后,集合的大小固定了,必须删除元素才能插入元素
            // (0,...,i-k,[i-(k-1),...,i-1,i],i+1,...,n-1) 要向右滑动窗口
            // nums[i-k+1]是窗口位置的第1个元素,需要被移除窗口
            // 10 - 8 = 2 : ...,8,9,10,... ;i - (i-k+1) = k - 1

            // window.erase(window.equal_range(nums[i - k + 1]).first);
            window.erase(window.find(nums[i - (k - 1)]));
            // }
        }

        return ans;
    }
};