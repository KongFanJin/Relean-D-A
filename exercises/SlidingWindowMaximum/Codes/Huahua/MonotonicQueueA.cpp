class MonotonicQueue{
public:
    void push(int e); // push an element on the queue,then will pop all elements smaller than e
    void pop(); // pop the first(max) element
    int max() const; // get the max element
};

/*
  滑动窗口的位置               Monotonic Queue		  最大值
---------------               --------------- 		-----
[1]  3  -1 -3  5  3  6  7     [1]					-	  push 1,1即为max  
[1  3]  -1 -3  5  3  6  7     [3]					-	  push 3, 3 > 1, 1出队
[1  3  -1] -3  5  3  6  7     [3,-1]				3     push -1, -1 < 3, -1入队; 3个元素了, 最大值3
 1 [3  -1  -3] 5  3  6  7     [3,-1,-3]				3     窗口移位1, push -3, -3 < -1, -3入队; 最大值3
 1  3 [-1  -3  5] 3  6  7     [5]					5     窗口移位1, push 5, 5 > -1; -1,-3出队; 最大值5
 1  3  -1 [-3  5  3] 6  7     [5,3]                 5     窗口移位1, push 3, 3 < 5, 3入队; 最大值5
 1  3  -1  -3 [5  3  6] 7     [6]                   6     窗口移位1, push 6, 6 > 5, 5出队; 最大值5
 1  3  -1  -3  5 [3  6  7]    [7]                   7     窗口移位1, push 7, 7 > 6, 6出队; 最大值7
*/

// Author: Huahua
/*
 https://zh.cppreference.com/w/cpp/container/deque
 std::deque （ double-ended queue ，双端队列）是有下标顺序容器，它允许在其首尾两段快速插入及删除。
 另外，在 deque 任一端插入或删除不会非法化指向其余元素的指针或引用。
 
 与 std::vector 相反， deque 的元素不是相接存储的：典型实现用单独分配的固定大小数组的序列，外加额外的登记，
 这表示下标访问必须进行二次指针解引用，与之相比 vector 的下标访问只进行一次。
*/
// 通过	516 ms 104.4 MB C++
// 时间复杂地分析:push+pop=n,O(n)
class MonotonicQueue{
public:
    void push(int e){
        while (!data_.empty() && e > data_.back()) // 出队比e小的元素,然后入队
            data_.pop_back();
        
        data_.push_back(e);
    }

    void pop(){ // pop最大的元素
        data_.pop_front();
    }

    int max() const { return data_.front(); } // get最大的元素

private:
    deque<int> data_;

class Solution{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k){
        MonotonicQueue q;
        vector<int> ans;

        for (int i = 0; i < nums.size(); ++i){
            q.push(nums[i]);
            if (i - k + 1 >= 0){ // 有足够的元素(k个)了
                ans.push_back(q.max()); // 取最大值加入ans中
                
                // 如果当前元素(...[...]i...)与窗口的当前最大元素相等时?
                // 若不等则nums[i - k + 1]一定小于q.max(),因为单调队列的front是最大值
                if (nums[i - k + 1] == q.max()) 
                    q.pop();
            }
        }
        return ans;
    }
};