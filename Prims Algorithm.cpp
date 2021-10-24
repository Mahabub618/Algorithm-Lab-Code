#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+100;
int V, m;
vector<pair<int, int> > g[N];
vector<int> path;
int parent[N], key[N];
bool mstSet[N];

int minKey()
{
    long long Min = INT_MAX;
    int idx;

    for(int u=1; u<=V; u++)
    {
        if(mstSet[u] == false and key[u] < Min)
        {
            Min = key[u];
            idx = u;
        }
    }
    return idx;
}
void Prims()
{
    for(int i=1; i<=V; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[1] = 0;
    parent[1] = -1;

    for(int i= 1; i<=V; i++)
    {
        long long u = minKey();
        mstSet[u] = true;
        path.push_back(u);

        for(auto x: g[u])
        {
            long long v = x.first;
            long long w = x.second;

            if(mstSet[v] == false and w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }
}
int main()
{
    long long u, v, w;
    cout << "Enter number of vertex: ";
    cin >> V;

    cout << "\nEnter number of edge: ";
    cin >> m;

    cout << "\nEnter pair of vertex and their cost: \n";
    for(int i=0; i<m; i++)
    {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    Prims();

    cout << "\nPrint the path of MST: \n";
    cout << "Edge \tCost\n";

    long long cost = 0;
    for(int i=2; i<=V; i++)
    {
        cout << parent[i] << " - " << i << " \t";
        for(auto x: g[i])
        {
            int v = x.first;
            int w = x.second;

            if(v == parent[i])
            {
                cout << w << " \n";
                cost += w;
                break;
            }
        }
    }

    cout << "\nTotal cost is: " << cost << endl;
}
