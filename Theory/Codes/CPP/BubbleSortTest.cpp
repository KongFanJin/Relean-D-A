#include <iostream>

using namespace std;

int main()
{
    // vector<int> nums{1,3,4,5,6,7,7,8,4,12,3,9};
    int nums[] = {1, 3, 4, 5, 6, 7, 7, 8, 4, 12, 3, 9};

    cout << "orgninal: ";
    for (auto i : nums)
        cout << i << " ";
    cout << "\n";

    for (int i = 0; i < 12 - 1; i++)
        for (int j = 0; j < 12 - i - 1; j++)
            if (nums[j] > nums[j + 1])
            {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }

    cout << "sorted: ";
    for(int i = 0; i < 12; i++)
        cout << nums[i] << " ";
    cout << "\n";
}