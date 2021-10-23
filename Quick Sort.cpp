#include<bits/stdc++.h>
using namespace std;

int parti(int arr[], int l, int r)
{
    int p = arr[r];
    int i = l-1;

    for(int j=l; j<r; j++)
    {
        if(arr[j] < p)
        {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i+1], arr[r]);

    return (i+1);
}
void Quick_Sort(int arr[], int l, int r)
{
    if(l < r)
    {
        int pivot = parti(arr, l, r);

        Quick_Sort(arr, l, pivot-1);
        Quick_Sort(arr, pivot+1, r);
    }
}
int main()
{
    int n;
    cout << "Enter number of inputs: ";
    cin >> n;

    int arr[n+1];
    cout << "\nEnter input of array: ";

    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    Quick_Sort(arr, 0, n-1);
    cout << "\nSorted array is: ";
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << ' ';
    }
}
