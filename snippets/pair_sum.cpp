#include <iostream>
#include <vector>
using namespace std;
vector<int> pair_sum(vector <int>& arr ,int target)
{ 
  vector <int> result;
  int left = 0,right = arr.size()-1;
  while (left < right)
    {
      
        if ( (arr[left]+arr[right]) > target )
        {
          right--;
        }
        else if (arr[left]+arr[right]<target)
        {
          left++;
        }
        else  
        {
          result.push_back(left);
          result.push_back(right);
          return result;
        }
    }
  return result;
}

int main()
{
  vector <int> arr;
  int size;
  cout << "Enter the number of elements : " ;
  cin >> size;
  for (int i = 0 ;i < size ;i++)
    {
      cout << "Enter the Element at index " << i << " : ";
      int val;
      cin >> val;
      arr.push_back(val);
    }
  int target;
  cout << "Enter the target sum : ";
  cin >> target;
  
  if (pair_sum(arr,target).size()==0)
    cout << "Pair Sum not found " << endl;
  else
    cout << pair_sum(arr,target)[0] << "," << pair_sum(arr,target)[1];
  cout << endl;
  return 0;
}
