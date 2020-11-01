#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> sortArray(vector<int> &nums) {
        // {3x+1} increment sequence : 1, 4, 13, 40, 121, 364, 1093, ...
        // 即采用变化的h = {1, 4, 13, 40, 121, 364, 1093, ...}
        int h = 1;
        while (h < nums.size() / 3) {
            h = 3 * h + 1;
        }

        while (h >= 1) {  // 直到h递减至1
            // // h-sort the array
            for (auto i = h; i != nums.size(); i++) {
                for (auto j = i; j >= h && nums[j] < nums[j - h]; j -= h)
                    swap(nums[j], nums[j - h]);
            }

            h = h + h / 3;
        }

        return nums;
    }
};

class Solution2 {
   public:
    vector<int> sortArray(vector<int> &nums) {
        int len = nums.size();
        for (int gap = len / 2; gap >= 1; gap /= 2) {
            for (int i = gap; i < len; i++) {
                if (nums[i] < nums[i - gap]) {
                    int temp = nums[i];
                    int j;
                    for (j = i - gap; j >= 0 && temp < nums[j]; j -= gap) {
                        nums[j + gap] = nums[j];
                    }
                    nums[j + gap] = temp;
                }
            }
        }
        return nums;
    }
};

class Solution3 {
public:
    vector<int> sortArray(vector<int>& nums){
		for(auto gap = nums.size()/2; gap > 0; gap = gap/2)
        	for(auto i = gap; i != nums.size(); i++){ 
        	    for(auto j = i; j != 0 && nums[j] < nums[j-gap]; j-=gap)
        	        swap(nums[j],nums[j-gap]);
        	}
    
         return nums;
    }
};

int main() {
    vector<int> nums{10, 3, 7, 4, 12, 5, 2};
    // int nums [] = {10,3,7,4,12,5,2};
    Solution sol;

    cout << "orgninal: ";
    for (auto i : nums) cout << i << " ";
    cout << "\n";

    nums = sol.sortArray(nums);
    // sol.sortArray(nums, 12);
    cout << "sorted: ";
    for (auto i : nums) cout << i << " ";
    cout << "\n";
}