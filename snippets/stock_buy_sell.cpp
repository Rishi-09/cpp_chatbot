#include <iostream>
#include <vector>
using namespace std;
int stock_buy_sell(vector <int>& prices)
{   
    int Max_Profit=0,Best_Buy = prices[0];
    for(int i=0;i<prices.size();i++)
    {
        if(Best_Buy>prices[i])  Best_Buy=prices[i];
        Max_Profit=max(Max_Profit,prices[i]-Best_Buy);
    }
    return Max_Profit;
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
    cout << "Max Profit:" << stock_buy_sell(arr) <<  endl;
    return 0;
}