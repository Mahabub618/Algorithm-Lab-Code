#include<bits/stdc++.h>
using namespace std;

void Merge(int arr[], int l, int mid, int r)
{
    int n = mid-l+1;
    int m = r-mid;

    int L[n+1] = {0};
    int R[m+1] = {0};

    for(int i=1; i<=n; i++)
    {
        L[i] = arr[l+i-1];
    }
    for(int i=1; i<=m; i++)
    {
        R[i] = arr[mid+i];
    }
    L[n+1] = INT_MAX;
    R[m+1] = INT_MAX;
    int i=1, j=1;

    for(int k=l; k<=r; k++)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
    }

}
void merge_sort(int arr[], int l, int r)
{
    if(l<r)
    {
        int mid = (l+r)/2;
        merge_sort(arr, l, mid);
        merge_sort(arr, mid+1, r);
        Merge(arr, l, mid, r);
    }
}
int main()
{
    int n;
    cout << "Enter number of inputs: ";
    cin >> n;

    cout << "\nEnter input of arrays: ";
    int arr[n+1];
    for(int i=1; i<=n; i++)
    {
        cin >> arr[i];
    }

    merge_sort(arr, 1, n);
    cout << "\nPrinted array is: ";
    for(int i=1; i<=n; i++)
    {
        cout << arr[i] << ' ';
    }

}
