#include<bits/stdc++.h>
using namespace std;

vector<pair<double, double> > item;
vector<pair<int, double> > sol;
bool comp(const pair<double, double> &x,  const pair<double, double> &y)
{
    return (x.first/x.second > y.first/y.second);
}
double Fr_Knap(int n, double cap)
{
    double sum = 0;
    sort(item.begin(), item.end(), comp);

    for(int i=0; i<n; i++)
    {
        if(item[i].second <= cap)
        {
            cap -= item[i].second;
            sum += item[i].first;
            sol.push_back({i+1, item[i].second});
        }
        else
        {
            sum += (item[i].first/item[i].second) * cap;
            sol.push_back({i+1, cap});
            cap = 0;
            break;
        }
    }
    return sum;
}
int main()
{
    int n;
    double cap, x;

    cout << "Enter knapsack capacity: ";
    cin >> cap;
    cout << "\nEnter Number of items: ";
    cin >> n;
    double a[n+1];
    cout << "\nEnter profit of items: ";
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    cout << "\nEnter weight of items: ";
    for(int i=0; i<n; i++)
    {
        cin >> x;
        item.push_back({a[i], x});
    }

    double Max = Fr_Knap(n, cap);
    cout << "\nMaximum Capacity is: " << setprecision(8) << fixed << Max << endl;

    cout << "\nItems are taken: \n";
    for(int i=0; i<sol.size(); i++)
    {
        cout << "Item -> " << sol[i].first << ": " << sol[i].second << " KG\n";
    }


}
