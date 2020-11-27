#include<iostream>
#include<vector>

using namespace std;

// 使用辅助空间
class Solution1 {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> nonZeroElements;

        for(int i = 0; i < nums.size(); i++)
            if(nums[i]) // 非零元素
                nonZeroElements.push_back(nums[i]);
        
        for(int i = 0; i < nonZeroElements.size(); i++)
            nums[i] = nonZeroElements[i];

        for(int i = nonZeroElements.size(); i < nums.size(); i++)
            nums[i] = 0;
    }
};

// 不使用辅助空间
// 因为0的数量一定小于数组的大小,遇到非0元素,将其前移
class Solution3 {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;
        for(int i = 0; i > nums.size(); i++)
            if(nums[i] > 0){
                swap(nums[k], nums[i]);
                k++;
            }   
    }
};