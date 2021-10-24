#include<bits/stdc++.h>
using namespace std;

int nod,edg,par[100005];

struct edge
{
    long long u,v,w;
    bool operator<(const edge& p) const
    {
        return w<p.w;
    }
};

vector<pair<int, pair<int, long long> > > path;

priority_queue<edge> pq;

int find(int r)
{
    if(par[r]==r)
        return r;
    return par[r]=find(par[r]);
}

void mst(void)
{
    for(int i=1; i<=nod; i++)
        par[i] = i;
    int cnt=0;
    long long sum = 0;
    while(!pq.empty())
    {
        edge top = pq.top();
        pq.pop();
        int u = top.u;
        int v = top.v;
        long long w = -top.w;
        int a = find(u);
        int b = find(v);
        if(a!=b)
        {
            sum+=w;
            cnt++;
            path.push_back({u, {v, w}});
            par[b] = par[a];
        }
        if(cnt==nod-1)
            break;
    }
    if(cnt == nod-1)
    {
        cout << "\nPrint the path of MST: \n";
        cout << "Edge \tCost\n";

        for(int i=0; i<path.size(); i++)
        {
            cout << path[i].first << " - " << path[i].second.first << "\t " << path[i].second.second << endl;
        }

        cout << "Total Cost of MST is: " << sum << endl;
    }
    else
    {
        cout << "MST is not possible\n";
    }
    while(!pq.empty())
    {
        pq.pop();
    }
}


int main()
{
    cout << "Enter number of node: ";
    cin >> nod;
    cout << "\nEnter number of edge: ";
    cin >> edg;
    cout << "\nEnter pair of edge and their cost: \n";

    for(int i=0; i<edg; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        edge get;
        if(u<v)
        {
            get.u = u;
            get.v  = v;
            get.w = -w;
        }
        else
        {
            get.u = v;
            get.v = u;
            get.w = -w;
        }
        pq.push(get);
    }
    mst();

    return 0;
}
