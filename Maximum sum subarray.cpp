#include<bits/stdc++.h>

using namespace std;
struct data
{
    int low, high, sum;
};
int a[100005], n;
data find_cross_subarray(int lo, int mid, int hi)
{
    int left_sum = INT_MIN, right_sum = INT_MIN;
    int mx1 = INT_MIN, mx2 = INT_MIN;
    int sum = 0, max_left=n, max_right=0;
    for(int i=mid; i>=0; i--)
    {
        sum += a[i];
        mx1 = max(mx1, a[i]);
        if(sum>left_sum)
        {
            left_sum = sum;
            max_left = i;
        }
    }

    sum = 0;
    mx2 = INT_MIN;
    for(int i=mid+1; i<=min(hi, n-1); i++)
    {
        sum += a[i];
        mx2 = max(mx2, a[i]);
        if(sum>right_sum)
        {
            right_sum = sum;
            max_right = i;
        }
    }

    if(left_sum == INT_MIN or right_sum == INT_MIN)
    {
        left_sum = max(mx1, mx2);
        right_sum = 0;
    }

    data d;
    d.low = max_left;
    d.high = max_right;
    d.sum = left_sum+right_sum;

    return d;
};
data find_maximum_subarray(int lo, int hi)
{
    int mid;
    data d, Left, Right, Cross;
    if(lo==hi)
    {
        d.low = lo;
        d.high = hi;
        d.sum = a[lo];
        return d;
    }
    else mid = (lo+hi)/2;

    Left = find_maximum_subarray(lo, mid);
    Right = find_maximum_subarray(mid+1, hi);
    Cross = find_cross_subarray(lo, mid, hi);

    if(Left.sum>=Right.sum and Left.sum>=Cross.sum) return Left;
    else if(Right.sum>=Left.sum and Right.sum>=Cross.sum) return Right;
    else return Cross;


}
int32_t main()
{
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "\nEnter input of the elements: ";
    for(int i=0; i<n; i++) cin >> a[i];
    data dat = find_maximum_subarray(0, n-1);
    cout << "\nMaximum sum subarray is: " << dat.sum << endl;
}
