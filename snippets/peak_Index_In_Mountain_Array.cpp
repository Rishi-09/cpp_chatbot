#include <iostream>
#include <vector>
using namespace std;
int peakIndexInMountainArray(vector<int>& arr)
{
        int left = 0,right=arr.size()-1,mid;
        while(left<=right)
        {
            mid = left+(right-left)/2;
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
                return mid;
            else if(arr[mid]<arr[mid+1] && arr[mid]>arr[mid-1])
                left = mid;
            else
                right = mid;
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
    int res = peakIndexInMountainArray(arr);
    if(res==-1)
        cout << "Element not found ." << endl;
    else
        cout << "Peak element is at index " << res << endl ;
    return 0;
}
