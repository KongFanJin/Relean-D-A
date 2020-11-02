#include <iostream>
#include <vector>

using namespace std;

class Solution1 {
   public:
    vector<int> sortArray(vector<int>& nums) {
        for (auto i = 0; i != nums.size(); i++) {  // 选出位置i
            int min = i;
            for (auto j = i + 1; j != nums.size(); j++) {  // 选出i之后的最小的元素
                if (nums[j] < nums[min]) min = j;
            }

            swap(nums[i], nums[min]);  // 交换位置,交换后nums[i]就是第i小的元素
        }

        return nums;
    }
};


class Solution2 {
   public:
    vector<int> sortArray(vector<int>& nums) {
        for (auto end = nums.size() - 1; end != 0; end--) {
            int max = end;
            for (auto begin = 0; begin < end; begin++)
                // > Descending Order 
                if (nums[max] < nums[begin]) max = begin;

            swap(nums[end], nums[max]);
        }

        return nums;
    }
};

int main() {
    vector<int> nums{10, 3, 7, 4, 12, 5, 2};
    // int nums [] = {10,3,7,4,12,5,2};
    Solution2 sol;

    cout << "orgninal: ";
    for (auto i : nums) cout << i << " ";
    cout << "\n";

    nums = sol.sortArray(nums);
    // sol.sortArray(nums, 12);
    cout << "sorted: ";
    for (auto i : nums) cout << i << " ";
    cout << "\n";
}