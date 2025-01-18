#include <iostream>
#include <vector>
using namespace std;
int SingleNum(vector <int> &num)
{ 
    int ans = 0;
    for(int i:num)
    {
        ans ^=i;       
    }
    return ans;
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
    cout << SingleNum(arr) << endl ;
}