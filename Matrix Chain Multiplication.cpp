#include<bits/stdc++.h>
using namespace std;

int tab[1001][1001];
int Matrix_Chain(int arr[], int i, int j)
{
    if(i==j) return 0;
    if(tab[i][j] != -1) return tab[i][j];

    tab[i][j] = INT_MAX;
    for(int k=i; k<j; k++)
    {
        tab[i][j] = min(tab[i][j], Matrix_Chain(arr, i, k) + Matrix_Chain(arr, k+1, j) + arr[i-1]*arr[k]*arr[j]);
    }
    return tab[i][j];
}
int main()
{
    cout << "Enter Number of dimensions: ";
    int n;
    cin >> n;

    int arr[n+1];
    cout << "\nEnter the dimensions: ";
    for(int i=0; i<=n; i++)
    {
        cin >> arr[i];
    }
    memset(tab, -1, sizeof tab);

    int ans =  Matrix_Chain(arr, 1, n);

    cout << "\nMinimum number of multiplication is: " << ans << endl;
}
