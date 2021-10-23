#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter Number of arrays: ";
    cin >> n;
    int arr[n+1];

    cout << "\nEnter input of array: ";
    for(int i=1; i<=n; i++)
    {
        cin >> arr[i];
    }

    for(int j=2; j<=n; j++)
    {
        int key = arr[j];
        int i = j-1;

        while(i > 0 and arr[i] > key)
        {
            arr[i+1] = arr[i];
            i = i-1;
        }
        arr[i+1] = key;
    }

    cout << "\nSorted array is: ";
    for(int i=1; i<=n; i++)
    {
        cout << arr[i] << ' ';
    }
}
