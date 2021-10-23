#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str1, str2;
    cout << "Enter the first String: ";
    cin >> str1;
    cout << "\nEnter the second String: ";
    cin >> str2;

    int m = str1.size();
    int n = str2.size();

    int tab[n+1][m+1];
    char ind[n+1][m+1];

    for(int i=0; i<=m; i++)
    {
        tab[0][i] = 0;
        ind[0][i] = '*';
    }
    for(int i=0; i<=n; i++)
    {
        tab[i][0] = 0;
        ind[i][0] = '*';
    }

    for(int i= 1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(str2[i-1] == str1[j-1])
            {
                tab[i][j] = tab[i-1][j-1]+1;
                ind[i][j] = 'C';
            }
            else if(tab[i-1][j] >= tab[i][j-1])
            {
                tab[i][j] = tab[i-1][j];
                ind[i][j] = 'U';
            }
            else
            {
                tab[i][j] = tab[i][j-1];
                ind[i][j] = 'L';
            }
        }
    }

    cout << "\nLongest Common Subsequence length: " << tab[n][m] << endl;

    int i = n, j = m;
    string ans;
    while(i > 0 and j > 0)
    {
        if(ind[i][j] == 'C')
        {
            ans += str1[j-1];
            i--;
            j--;
        }
        else if(ind[i][j] == 'L') j--;
        else i--;
    }
    reverse(ans.begin(), ans.end());

    cout << "Longest Common Subsequence is: " << ans << endl;

}
