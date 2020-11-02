#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums){
        // 最后一趟扫描元素就一个而且最小,不用比较,故需要n-1趟
        for(auto i = 0; i != nums.size() - 1; i ++)
            // 每趟扫描将最大元素交换到a[n-1-i]的位置
            for(auto j = 0; j != (nums.size() - 1) - i; j++)
                if(nums[j] > nums[j+1]) 
                    swap(nums[j],nums[j+1]);
        
        return nums;
    }
};


class Solution1 {
public:
    vector<int> sortArray(vector<int>& nums){
        // 发生交换设为true,未发生交换说明是不递减序列,设为false跳出比较
        bool flag = true;
        for(auto i = 0; flag && i != nums.size() - 1; i ++){
            flag = false; 
            for(auto j = 0; j != (nums.size() - 1) - i; j++)
                if(nums[j] > nums[j+1]) {
                    swap(nums[j],nums[j+1]);
                    flag = true;
                }
        }

        return nums;
    }
};

// Bubble Sort
// increasing order
class Solution3 {
public:
    vector<int> sortArray(vector<int>& nums){
        // 最后一趟扫描元素就一个而且最小,不用比较,故需要n-1趟
        for(auto i = nums.size() - 1; i != 0; i --)
            // 比较nums[j]和nums[j+1],大者向右交换(移动)
            // 每趟扫描将最大元素交换到a[(n-1)-i]的位置
            for(auto j = 0; j != i; j++)
                if(nums[j] > nums[j+1]) 
                    swap(nums[j],nums[j+1]);
        
        return nums;
    }
};

// Bubble SortX2
// Add Flag
// 数组的尾部元素有序时
// 记录最后一次的交换的元素的位置,减少比较次数
// 恋上数据结构第二季
class Solution4 {
public:
    vector<int> sortArray(vector<int>& nums){
        auto index = 1;
        for(auto i = 0; i != nums.size() - 1; i ++){
            for(auto j = 0; j != (nums.size() - 1) - i; j++)
                if(nums[j] > nums[j+1]){
                    swap(nums[j],nums[j+1]);   
                    index = j + 1; // 记录本趟最后交换元素的位置
                }
            
            i = (nums.size() - 1)-index;
        }
        return nums;
    }
};


class Solution5 {
public:
    vector<int> sortArray(vector<int>& nums){
        for(auto i = nums.size() - 1; i != 0; i --){
            int index = 0;
            for(auto j = 0; j != i; j++)
                if(nums[j] > nums[j+1]){
                    swap(nums[j],nums[j+1]);
                    index = j + 1;
                }
           i =  index;        
        }

        
        return nums;
    }
};


int main(){
    vector<int> nums{10,3,7,4,12,5,2};
    // int nums [] = {10,3,7,4,12,5,2};
    Solution4 sol;

    cout << "orgninal: ";
    for(auto i : nums)
        cout << i << " ";
    cout << "\n";

    nums = sol.sortArray(nums);
    // sol.sortArray(nums, 12);
    cout << "sorted: ";
    for(auto i : nums)
        cout << i << " ";
    cout << "\n";
}