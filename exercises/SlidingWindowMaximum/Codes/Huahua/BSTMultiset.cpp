// Author: Huahua

// https://docs.microsoft.com/zh-cn/cpp/standard-library/multiset-class?view=vs-2019
/*
   The C++ Standard Library multiset class is used for the storage and retrieval of data from a collection 
   in which the values of the elements contained need not be unique and in which they serve as the key values 
   according to which the data is automatically ordered. The key value of an element in a multiset may not be changed directly. 
   Instead, old values must be deleted and elements with new values inserted.
*/

/*
  multiset::rbegin()
  Returns a const iterator addressing the first element in a reversed multiset.
  
  multiset::equal_range()
  Returns a pair of iterators. 
  The first iterator in the pair points to the first element in a multiset with a key that is greater than a specified key. 
  The second iterator in the pair points to the first element in the multiset with a key that is equal to or greater than the key.
  
   If no match is found for the key, both elements of the pair return end( )

  就是返回: first <= e <= second

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

        // 将[0,0+k-1)的k个元素加入到multiset中
        // 创建完集合后,集合的大小固定了,必须删除元素才能插入元素
        multiset<int> window(nums.begin(), nums.begin() + k-1); 
        for (int i = k - 1; i < nums.size(); ++i) {
            window.insert(nums[i]); // 插入
            ans.push_back(*window.rbegin()); // multiset默认递增序列;获得最大值,存入ans

            if (i - k + 1 >= 0) //窗口有k个元素时
                window.erase(window.equal_range(nums[i - k + 1]).first); // 删除比nums[i - k + 1]的元素
        }

        return ans;
    }
};