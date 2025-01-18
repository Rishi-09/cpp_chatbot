#include <iostream>
#include <vector>
using namespace std;
int singleNonDuplicate(vector<int> &nums)
{
    int left = 0, right = nums.size() - 1, mid;
    if (right == 0)
        return nums[right];
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (mid == 0 && nums[mid] != nums[mid + 1])
            return nums[mid];
        if (mid == right && nums[right] != nums[right - 1])
            return nums[mid];
        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
            return nums[mid];
        else if (mid % 2 != 0)
        {
            if (nums[mid] == nums[mid - 1])
                left = mid + 1;
            else
                right = mid - 1;
        }
        else
        {
            if (nums[mid] == nums[mid - 1])
                right = mid - 1;
            else
                left = mid + 1;
        }
    }
    return -1;
}
