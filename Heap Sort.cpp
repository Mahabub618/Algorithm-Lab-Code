#include<bits/stdc++.h>
using namespace std;
void Heapify(int arr[], int n, int i)
{
    int Max = i;
    int Left = 2*i + 1;
    int Right = 2*i + 2;

    if(Left < n and arr[Left] > arr[Max])
    {
        Max = Left;
    }
    if(Right < n and arr[Right] > arr[Max])
    {
        Max = Right;
    }

    if(Max != i)
    {
        swap(arr[Max], arr[i]);

        Heapify(arr, n, Max);
    }
}
void Heap_Sort(int arr[], int n)
{
    for(int i=n/2-1; i>=0; i--)
    {
        Heapify(arr, n, i);
    }
    for(int i=n-1; i>0; i--)
    {
        swap(arr[i], arr[0]);

        Heapify(arr, i, 0);
    }
}
int main()
{
    int n;
    cout << "Enter number of input: ";
    cin >> n;

    int arr[n+1];
    cout << "\nEnter input of array: ";
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    Heap_Sort(arr, n);

    cout << "\nThe Sorted array is: ";
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << ' ';
    }
}
