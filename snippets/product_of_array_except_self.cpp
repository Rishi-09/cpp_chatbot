#include <iostream>
#include <vector>
using namespace std;
vector<int> productExceptSelf(vector<int> &nums)
{
    vector <int> ans(nums.size(),1);
     for (int i = 0;i<nums.size();i++)
        {   
            for(int j=0;j<nums.size();j++)
            {
                if(i!=j) {
                    ans[i]*=nums[j];
                }
            }
        }
        return ans;
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
    vector <int> res = productExceptSelf(arr);
    for (int i = 0; i < size; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}