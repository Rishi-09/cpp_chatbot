#include <iostream>
#include <vector>
using namespace std;
int MaxSumArray(vector <int> arr)
{
    int max_sum=arr[0],current_sum=0;
    for(int i =0 ; i<arr.size();i++)
    {
        current_sum += arr[i];
        max_sum = max(current_sum,max_sum);
        if (current_sum <0)
        {
            current_sum=0;
        }
    }
    return max_sum;
}
int main()
{

	vector <int> arr;
    int n;
    cout << "enter number of elements :";
    cin >> n;
	for ( int i =0 ; i< n ;i++)
	{	cout << "Enter Element at index " << i << " : " ;
		int val;
		cin >> val;
		arr.push_back(val);
		
	}
	cout << "Entered Array :";
	for ( int i =0 ; i< n ;i++)
	{
		cout << arr[i] <<  " ";
		
	}	
	cout << endl;
    cout << MaxSumArray(arr) << endl;
}