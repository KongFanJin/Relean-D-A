#include<vector>
#include<iostream>

using namespace std;

// Bubble SortX2
// Add Flag
// 数组的尾部元素有序时
// 记录最后一次的交换的元素的位置,减少比较次数
// 恋上数据结构第二季

// Bubble Sort
// increasing order
class Solution1 {
public:
    vector<int> sortArray(vector<int>& nums){
        for(auto i = nums.size() - 1; i != 0; i --){
            int index = 0;
            for(auto j = 0; j != i; j++)
                if(nums[j] > nums[j+1]){
                    swap(nums[j],nums[j+1]);
                    index = j; // 记录本趟最后交换元素的位置
                }

           i =  index;        
        }
        
        return nums;
    }
};

// Bubble SortX2-1
// Add Flag
// 数组的尾部元素有序时
// 记录最后一次的交换的元素的位置,减少比较次数
// 从左到右(有问题未解决)
class Solution2 {
public:
    vector<int> sortArray(vector<int>& nums){
        int index = 0;
        for(auto i = 0; i != nums.size() - 1; i ++){
            auto index = 0;

            // j != (nums.size() - 1) - i 如何加入上次的比较位置index,这样就不用进入循环体了,从而减少比较次数
            for(auto j = 0; j != (nums.size() - 1) - i; j++) 
                if(nums[j] > nums[j+1]){
                    swap(nums[j],nums[j+1]);   
                    index = j + 1; // 记录本趟最后交换元素的位置
                }
        }
        return nums;
    }
};

int main(){
    // vector<int> nums{10,3,7,4,12,5,2};
    vector<int> nums{6,4,5,3,2,1,7,8,9};
    // int nums [] = {10,3,7,4,12,5,2};
    Solution2 sol;

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