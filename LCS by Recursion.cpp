#include<bits/stdc++.h>
using namespace std;
string str1, str2;

int LCS(int ind1, int ind2)
{
    if(str1[ind1]=='\0' or str2[ind2]=='\0') return 0;
    else if(str1[ind1] == str2[ind2])
    {
        return 1+LCS(ind1+1, ind2+1);
    }
    else
    {
        return max(LCS(ind1+1, ind2), LCS(ind1, ind2+1));
    }
}
int main()
{
    cout << "Enter the First String: ";
    cin >> str1;
    cout << "\nEnter the Second String: ";
    cin >> str2;

    int Max = LCS(0, 0);
    cout << "\nLongest Common Subsequence length is: " << Max << endl;
}
