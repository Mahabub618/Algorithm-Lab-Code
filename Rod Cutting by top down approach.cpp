#include<bits/stdc++.h>
using namespace std;

int rod_cut_aux(int p[], int n, int r[])
{
    int q;
    if(r[n]>=0) return r[n];

    if(n==0) q = 0;
    else q = INT_MIN;

    for(int i=1; i<=n; i++)
    {
        q = max(q, p[i]+rod_cut_aux(p, n-i, r));
    }
    r[n] = q;
    return r[n];
}

int rod_cut(int p[], int n)
{
    int r[n+1];
    for(int i=0; i<=n; i++) r[i] = INT_MIN;

    return rod_cut_aux(p, n, r);
}

int main()
{
    int n;
    cout << "Enter length of rod: ";
    cin >> n;
    int a[n+1];
    a[0]=0;
    for(int i=1; i<=n; i++)
    {
        cout << "Price of length " << i << ": ";
        cin >> a[i];
    }
    int ans = rod_cut(a, n);
    cout << "Maximum profit of rod cutting is: " << ans << endl;
}
