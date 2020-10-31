#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums){
        // {3x+1} increment sequence : 1, 4, 13, 40, 121, 364, 1093, ... 
        // 即采用变化的h = {1, 4, 13, 40, 121, 364, 1093, ...}
		int h = 1;
        while(h < nums.size()/3){
            h = 3*h + 1;
        }
        
        while(h >= 1){ // 直到h递减至1
            // // h-sort the array
            for(auto i = h; i != nums.size(); i++){
                for(auto j = i; j >= h && nums[j] < nums[j-h]; j -= h)
                    swap(nums[j], nums[j-h]);
            }
            
            h = h + h/3;
        }
        
        return nums;
    }
};

int main(){
    vector<int> nums{10,3,7,4,12,5,2};
    // int nums [] = {10,3,7,4,12,5,2};
    Solution sol;

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