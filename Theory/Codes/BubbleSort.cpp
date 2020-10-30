#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums){
        for(auto i = 1; i != nums.size() - 1; i ++)
            for(auto j = 0; j != nums.size() - i; j++)
                if(nums[j] > nums[j+1]) 
                    swap(nums[j],nums[j+1]);
        
        return nums;
    }
};


class Solution1 {
public:
    vector<int> sortArray(vector<int>& nums){
        for(auto i = 0; i != nums.size() - 1; i ++)
            for(auto j = 0; j != nums.size() - i - 1; j++)
                if(nums[j] > nums[j+1]) 
                    swap(nums[j],nums[j+1]);
        
        return nums;
    }
};

// 有问题 flag跳出的位置
class Solution2 {
public:
    vector<int> sortArray(vector<int>& nums){
        bool flag = true;
        for(auto i = 0; i != nums.size() - 1 && flag; i ++)
            for(auto j = 0; j != nums.size() - i - 1; j++)
                if(nums[j] > nums[j+1]) {
                    swap(nums[j],nums[j+1]);
                    flag = false;
                }
        
        return nums;
    }
};

class Solution3 {
public:
    vector<int> sortArray(vector<int>& nums){
        for(auto i = nums.size() - 1; i != 0; i --)
            for(auto j = 0; j != i; j ++)
                if(nums[j] > nums[j+1]) 
                    swap(nums[j],nums[j+1]);
        
        return nums;
    }
};

class Solution4 {
public:
    void sortArray(int nums[], int size){
        for(auto i = size - 1; i != 0; i --)
            for(auto j = 0; j != i; j ++)
                if(nums[j] > nums[j+1]) 
                    swap(nums[j],nums[j+1]);
    }
};

class Solution5 {
public:
    void sortArray(int nums[], int size){
        for(int i = 0; i < size - 1; i ++)
            for(int j = 0; j < size - i - 1; j ++)
                if(nums[j] > nums[j+1]) {
                    int temp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = temp;
                }
    }
};

// 有问题
class Solution6 {
public:
// Bubble Sort
    vector<int> sortArray(vector<int>& nums){
        for(auto i = 0; i != nums.size(); i ++){
            for(auto j = 0; j != i; j++)
                if(nums[j] > nums[j+1]) swap(nums[j],nums[j+1]);
        }
        return nums;
    }
};

int main(){
    vector<int> nums{1,3,4,5,6,7,7,8,4,12,3,9};
    // int nums [] = {1,3,4,5,6,7,7,8,4,12,3,9};
    Solution6 sol;

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