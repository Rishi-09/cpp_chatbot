#include <iostream>
#include <vector>
bool isvalid(vector<int>arr,int k,int allowedpages)
    {
        int n = arr.size();
        int student = 1,pages =0;
        for(int i = 0;i<n;i++)
        {
            if(arr[i]>allowedpages)
                return false;
            if(pages+arr[i]<=allowedpages)
            {
                pages+=arr[i];
            }
            else
                {student ++; pages=arr[i];}
        }
        return student>k?false:true;
}  
int findPages(vector<int> &arr, int k) {
        int n=arr.size();
        if(n<k) return -1;
        int maxPages = 0;
        for(int i =0;i<n;i++)
            maxPages +=arr[i];
        int left =0,right=maxPages,mid,ans=-1;
        while(left<=right)
        {
            mid=left+(right-left)/2;
            if(isvalid(arr,k,mid))
             { ans=mid; 
              right= mid-1;
             }
            else
                left = mid+1;
        }
        return ans;
    }