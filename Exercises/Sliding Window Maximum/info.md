---
tags:
    - 剑指Offer第2版/59
    - hard
    - LeetCode/239
    - MonotonicQueue
    - Multiset
    - SlidingWindow
created: 2020-10-23T08:15:44.232Z
modified: 2020-10-25T22:28:33.755Z
---
[LeetCode 239. Sliding Window Maximum](https://leetcode-cn.com/problems/sliding-window-maximum/)

[剑指 Offer 59 - I. 滑动窗口的最大值](https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/)

参考

- [花花酱 LeetCode 239 [C++]](https://www.bilibili.com/video/BV1WW411C763)
- [Huifeng Guan](https://www.youtube.com/watch?v=b1rqOQ5p6EA)

# 题目描述

给定一个数组 `nums`，有一个大小为 `k` 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 `k `个数字。滑动窗口每次只向右移动一位。

要求:返回滑动窗口中的最大值。

# 示例

```
输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7] 
解释: 

  滑动窗口的位置                最大值

---------------               -----

[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
```

# 要求

- $1 <= nums.length <= 10^5$
- $-10^4 <= nums[i] <= 10^4$
- $1 <= k <= nums.length$

# 进阶

你能在线性时间复杂度内解决此题吗？


# Brute Force

扫描每个滑动窗口的所有数字并找出其中的最大值.

## 代码



> 不涉及代码的格式等细节

```C++
int max (vector<int> win){	
	int m = win[0];
	for(auto i ; win){
		if(i > m) m = i;
	}
	return m;
} 

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
	vector<int> win{};
	vector<int> maxSW{};
	
	for(auto i = 0; i < nums.lengths-k; i++){
		for(auto j = i, m = 0; j < i + k; j++, m++)
			win[m] = nums[j];	
		
		maxSW[i] = max(win);
	}
}
```

**错误分析**

```c++
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> win{};
        vector<int> maxSW{};

        for (auto i = 0; i < nums.size() - k; i++)
        {
            for (auto j = i, m = 0; j < i + k; j++, m++)
                win[m] = nums[j];

            maxSW[i] = max(win);
        }

        return maxSW;
    }

    int max(vector<int> win)
    {
        int m = win[0];
        for (auto& i : win)
            if (i > m)
                m = i;
        
        return m;
    }
};
```

**错误提示**

```
Line 1034: Char 9: runtime error: reference binding to null pointer of type 'int' (stl_vector.h)
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior /usr/bin/../lib/gcc/x86_64-linux-gnu/9/../../../../include/c++/9/bits/stl_vector.h:1043:9
```

**错误分析**

# 代码参考

[跳转](Codes)

## BruteForce

```C++
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
```

## BST/Multiset

```C++
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
```

## MonotonicQueue

```C++
class MonotonicQueue {
   public:
    void push(int e);  // push an element on the queue,then will pop all
                       // elements smaller than e
    void pop();        // pop the first(max) element
    int max() const;   // get the max element
};
```
```
  滑动窗口的位置              Monotonic Queue  最大值
---------------              ---------------  ------
[1]  3  -1 -3  5  3  6  7    [1]			   -     push 1,1即为max 
[1  3]  -1 -3  5  3  6  7    [3]               -	 push 3, 3 > 1, 1出队
[1  3  -1] -3  5  3  6  7    [3,-1]			   3     push -1,-1 < 3, -1入队; 3个元素了, 最大值3 
1 [3  -1  -3]  5  3  6  7    [3,-1,-3]         3     窗口移位1, push -3, -3 < -1, -3入队; 最大值3 
1  3 [-1  -3   5] 3  6  7    [5]               5     窗口移位1, push 5, 5 > -1; -1,-3出队; 最大值5 
1  3  -1 [-3   5  3] 6  7    [5,3]             5     窗口移位1, push 3, 3 < 5, 3入队; 最大值5 
1  3  -1 -3   [5  3  6] 7    [6]               6     窗口移位1, push 6, 6 > 5, 5出队; 最大值5 
1  3  -1  -3  5  [3  6  7]   [7]               7     窗口移位1, push7, 7 > 6, 6出队; 最大值7
```
```C++
// Author: Huahua
/*
 https://zh.cppreference.com/w/cpp/container/deque
 std::deque （ double-ended queue
 ，双端队列）是有下标顺序容器，它允许在其首尾两段快速插入及删除。 另外，在 deque
 任一端插入或删除不会非法化指向其余元素的指针或引用。

 与 std::vector 相反， deque
 的元素不是相接存储的：典型实现用单独分配的固定大小数组的序列，外加额外的登记，
 这表示下标访问必须进行二次指针解引用，与之相比 vector 的下标访问只进行一次。
*/
// 通过	516 ms 104.4 MB C++
// 时间复杂地分析:push+pop=n,O(n)
class MonotonicQueue {
   public:
    void push(int e) {
        while (!data_.empty() && e > data_.back())  // 出队比e小的元素,然后入队
            data_.pop_back();

        data_.push_back(e);
    }

    void pop() {  // pop最大的元素
        data_.pop_front();
    }

    int max() const { return data_.front(); }  // get最大的元素

   private:
    deque<int> data_;

    class Solution {
       public:
        vector<int> maxSlidingWindow(vector<int> &nums, int k) {
            MonotonicQueue q;
            vector<int> ans;

            for (int i = 0; i < nums.size(); ++i) {
                q.push(nums[i]);

                if (i - k + 1 >= 0) {        // 有足够的元素(k个)了
                    ans.push_back(q.max());  // 取最大值加入ans中

                    // 若不等则nums[i - (k - 1)]一定小于q.max(),然后在push就会被pop
                    // 若相等,需要滑动窗口时,nums[i - (k - 1)]也需要被pop
                    if (nums[i - (k - 1)] == q.max()) q.pop();
                }
            }
            return ans;
        }
    };
```

```C++
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
```

```C++
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
```



# 总结(待整理)

- 熟悉已有的工具(库)的性质
- 尽量要用现有工具解决问题
