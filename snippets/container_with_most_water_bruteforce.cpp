#include <iostream>
#include <vector>
using namespace std;
int MaxArea(vector<int> &height)
{
    int max_area = 0, Current_Area=0;
    for (int i = 0; i < height.size(); i++)
    {
        for (int j = i+1; j < height.size();j++)
        {
             Current_Area = (j - i) * min(height[j],height[i]);
            if (Current_Area > max_area)
                max_area = Current_Area;
        }
        max_area=max(max_area,Current_Area);
    }
    return max_area;
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
    cout << "Max area is :" << MaxArea(arr) << endl;
}