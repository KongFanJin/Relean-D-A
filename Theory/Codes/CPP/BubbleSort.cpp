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

int main(){
    vector<int> nums{10,3,7,4,12,5,2};
    // int nums [] = {10,3,7,4,12,5,2};
    Solution1 sol;

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