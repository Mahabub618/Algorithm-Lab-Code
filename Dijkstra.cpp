#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+100;
vector<pair<int, int> > g[N];
int dis[N];

int main()
{
    int n, m;
    cout << "Enter Number of Vertex: ";
    cin >> n;
    cout << "\nEnter Number of Edge: ";
    cin >> m;
    cout << "\nEnter pair of vertex and cost of this edge: ";
    for(int i=1; i<=m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    priority_queue<pair<int, int> > pq;

    for(int i=1; i<=n; i++) dis[i] = 1e9+9;

    cout << "\nEnter Source vertex: ";
    int src;
    cin >> src;
    dis[src] = 0;
    pq.push({-dis[src], src});

    while(pq.size()>0)
    {
        auto t = pq.top();
        pq.pop();

        int u = t.second, d = -t.first;

        if(dis[u]<d) continue;
        for(int i=0; i<g[u].size(); i++)
        {
            int v = g[u][i].first, w = g[u][i].second;

            if(dis[v]>dis[u]+w)
            {
                dis[v] = dis[u]+w;
                pq.push({-dis[v], v});
            }
        }
    }
    cout << "Vertex \t" << "Distance from source\n";
    for(int i=1; i<=n; i++)
    {
        cout << i << " \t\t" << dis[i] << endl;
    }
    return 0;
}
