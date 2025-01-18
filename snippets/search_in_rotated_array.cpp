#include <iostream>
#include <vector>
using namespace std;
int search_in_rotated_array(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1, mid;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (target == nums[mid])
            return mid;
        else if (nums[left] <= nums[mid])
        {
            if (nums[left] <= target && target <= nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        else
        {
            if (nums[mid] <= target && target <= nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return -1; 
}
int main()
{
    vector<int> arr;
    int size;
    cout << "Enter number of elements in array : ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        int val;
        cout << "Enter element at index " << i << " :";
        cin >> val;
        arr.push_back(val);
    }
    int target;
    cout << "Enter element to search :";
    cin >> target;
    int res = search_in_rotated_array(arr, target);
    if (res == -1)
        cout << "Element not found ." << endl;
    else
        cout << "Element found at index " << res << endl;
    return 0;
}
