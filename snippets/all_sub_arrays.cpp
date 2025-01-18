#include <iostream>
using namespace std;
#include <vector>
int main()
{
    vector<int> arr ;
    int size;
    cout << "Enter number of elements in array : ";
    cin >> size;
    for (int i = 0 ; i < size;i++)
    {
        int val;
        cout << "Enter element at index " << i << " :";
        cin >> val;
        arr.push_back(val);
    }
    for(int i = 0 ; i < size ; i++)
    {
        for(int j= i ; j < size ; j++)
        {
            for(int k = i ; k <=j;k++)
            {
                cout << arr[k];
            }
            cout << " ";
        }
        cout << endl;
    }
}