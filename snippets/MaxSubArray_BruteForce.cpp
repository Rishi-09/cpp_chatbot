#include <iostream>
#include <vector>
using namespace std;
int MaxSubarraySum(vector <int> arr)
{   
    int max_sum = 0;
    for(int i=0;i<arr.size();i++)
    {   int current_sum=0;
        for(int j = 0 ; j<i;j++)
            current_sum +=arr[j];
            max_sum= max(current_sum,max_sum);
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
    cout << MaxSubarraySum(arr) << endl;
}