#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    cout << "Enter length of rod: ";
    cin >> n;

    cout << "\nPrice of each length: ";
    int price[n+1], tab[n+1][n+1];
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            tab[i][j] = 0;
        }
    }
    for(int i=1; i<=n; i++)
    {
        cin >> price[i];
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(j<i) tab[i][j] = tab[i-1][j];
            else
            {
                tab[i][j] = max(tab[i-1][j], price[i]+tab[i][j-i]);
            }
        }
    }

    int i = n, j = n;
    vector<int> cutPoint;
    while(i> 0 and j>0)
    {
        if(tab[i][j] == tab[i-1][j]) i--;
        else
        {
            cutPoint.push_back(i);
            j = j-i;
        }
    }

    cout<< "\nMaximum Profit is: " << tab[n][n] << endl;
    cout << "Cutting point is: ";
    for(int i=0; i<cutPoint.size(); i++)
    {
        cout << cutPoint[i] << ' ';
    }
    cout << endl;
}
