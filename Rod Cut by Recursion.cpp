#include<bits/stdc++.h>
using namespace std;

int Cut_Rod(int price[], int n)
{
    if(n==0) return 0;
    int q = INT_MIN;
    for(int i=1; i<=n; i++)
    {
        q = max(q, price[i] + Cut_Rod(price, n-i));
    }
    return q;
}
int main()
{
    int n;
    cout << "Enter the length of rod: ";
    cin >> n;
    int price[n+1];

    cout << "\nEnter the price of each length: ";
    for(int i=1; i<=n; i++)
    {
        cin >> price[i];
    }

    int Max_Profit = Cut_Rod(price, n);

    cout << "\nMaximum Profit is: " << Max_Profit << endl;
}
