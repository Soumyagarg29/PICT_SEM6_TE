/*
Disjoint set
used in dynamic graphs 
1. to find parent
2. to find union 
3. to find cycle
         --> by size
         --> by rank



Steps to find union

1. find ultimate parent of u and v i.e pu and pv
2. find rank of pu  pv
3. connect smaller rank to larger rank always 

Time Complexity: O(E * logE) or O(E * logV) 

Sorting of edges takes O(E * logE) time. 
After sorting, we iterate through all edges and apply the find-union algorithm. The find and union operations can take at most O(logV) time.
So overall complexity is O(E * logE + E * logV) time. 
The value of E can be at most O(V2), so O(logV) and O(logE) are the same. Therefore, the overall time complexity is O(E * logE) or O(E*logV)
Auxiliary Space: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
*/




#include<bits/stdc++.h>
using namespace std;

class DSU
{
    int * parent;
    int * rank;
    public:
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];
        for(int i =0;i<n;i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
    }


    int findPar(int i)
    {
        if(parent[i] == -1)
        {
            return i;
        }
        return parent[i] = findPar(parent[i]);
    }

    void unionn(int u , int v)
    {
        int pu = findPar(u);
        int pv = findPar(v);
        if(pu != pv)
        {
            if(rank[pu] < rank[pv])
            {
                parent[pu] = pv;
            }
            else if(rank[pu] > rank[pv])
            {
                parent[pv] = pu;
            }
            else
            {
                parent[pu] = pv;
                rank[pv]++;
            }
        }
    }
};



class Graph
{
vector<vector<int>>edgeList;
vector<vector<pair<int , int>>>adj;
int V;
int edgecount;
public:
Graph(int v)
{
    V = v;
    adj.resize(V);
    cout<<"Enter no of edges:";
    cin>>edgecount;
    for(int i =0;i<edgecount;i++)
    {
        int u,v,w;
        cout<<"Enter u v w:";
        cin>>u>>v>>w;
        addEge(u,v,w);
        createAdj(u,v, w);
    }
}

void createAdj(int u, int v , int w)
{
adj[u].push_back({v,w});
adj[v].push_back({u,w});
}
void addEge(int u , int v , int w)
{
    edgeList.push_back({w,u,v});
}


void krushkal()
{   cout<<"Krushkal algo:"<<endl;
    sort(edgeList.begin() , edgeList.end());
    vector<pair<int , int>>mst;
    int ans = 0;
    DSU s(V);
    for(auto edge : edgeList)
    {
        int w = edge[0];
        int u = edge[1];
        int v = edge[2];
        if(s.findPar(u) != s.findPar(v))
        {
            mst.push_back({u,v});
            cout<<u<<" "<<v<<" "<<w<<endl;
            ans+=w;
            s.unionn(u,v);
        }
    }
    cout<<"Minimum cost is :"<<ans<<endl;
}

void prims()
{
    vector<int>parent(V , -1);
    vector<int>key(V , INT_MAX);
    vector<bool>mstSet(V , false);
    priority_queue<pair<int ,int> , vector<pair<int ,int>> , greater<pair<int ,int>>>pq;
    key[0] = 0;
    parent[0] = -1;
    pq.push({0,0});
    int sum =0;
    while(!pq.empty())
    {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        mstSet[u] = true;
        sum+=w;
        for(auto it : adj[u])
        {
            int v = it.first;
            int wt = it.second;
            if(mstSet[v] == false && wt<key[v])
            {
                parent[v] = u;
                key[v] = wt;
                pq.push({key[v] , v});
            }
        }
    }


    for(int i =1;i<V;i++)
    {
        cout<<parent[i]<<"-"<<i<<endl;
    }

    cout<<"Weight of the mst is : "<<sum<<endl;

}

};


int main()
{
    int v;
    cout<<"Enter no of vertices:";
    cin>>v;
    Graph g(v);
    g.krushkal();
    g.prims();
    return 0;
}


/*Time Complexity: O(E * logE) or O(E * logV) 

Sorting of edges takes O(E * logE) time. 
After sorting, we iterate through all edges and apply the find-union algorithm. The find and union operations can take at most O(logV) time.
So overall complexity is O(E * logE + E * logV) time. 
The value of E can be at most O(V2), so O(logV) and O(logE) are the same. Therefore, the overall time complexity is O(E * logE) or O(E*logV)
Auxiliary Space: O(V + E), where V is the number of vertices and E is the number of edges in the graph.*/