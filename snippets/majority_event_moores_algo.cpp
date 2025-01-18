#include <iostream>
using namespace std;
#include <vector>
int Majority_event(vector<int> &arr)
{
    int count = 0, ans = arr[0];
    for (int i :arr)
    {
        if (count == 0)
            ans = arr[i];
        if (ans == arr[i])
            count++;
        else
            count--;
    }
    int c = 0;
    for(int i : arr)
    {
        if (ans == arr[i])
            c++;
    }
    if (c>arr.size()/2)
        return ans;
    else
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
    if(Majority_event(arr)==-1)
        cout << "No element is occuring more than once .";
    else
        cout << "Most occuring element is : " << Majority_event(arr) << endl;
}