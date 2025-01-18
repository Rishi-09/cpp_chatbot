
#include <iostream>
#include <vector>
using namespace std;
bool isvalid(vector <int>& arr,int allowedtime,int m)
{	int n = arr.size();
    int painter = 1,time = 0;
	for (int i =0;i<n;i++)
	{
		if(time<=allowedtime)
			time+=arr[i];
		else
			painter++;
			time=arr[i];
	}
	time<=allowedtime?true:false;
}
int PainterPartition(vector <int>& arr,int m)
{
	int n = arr.size();
	int maxtime=0,ans;
	for(int i = 0;i<n;i++)
	{
		maxtime+=arr[i]; 
	}
	int left = 0 ,right = maxtime,mid;
	ans =-1;
	while(left<=right)
	{
		mid = left + (right-left)/2;
		if(isvalid(arr,mid,m))
		{
			ans = mid;
			right = mid -1;
		}
		else
			left = mid +1 ;
	}
	return ans;
}								

int main()
{
	vector <int> arr;
	arr = {10,10,10,10};
	int m;
	cout << "Enter the number of painters :";
	cin >> m;
	cout << PainterPartition(arr,m) << endl;
	return 0;
}