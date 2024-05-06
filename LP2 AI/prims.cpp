#include<bits/stdc++.h>
using namespace std;


// Travelling salesperson problem using MST - Prims
int minKey(vector<int>key ,vector<bool>mstSet)
{
int min = INT_MAX , min_index = 0;

for(int u=0;u<key.size();u++)
{
if(mstSet[u] == false && key[u] < min )
{
min=key[u] , min_index = u;

}
}

 return min_index;
}
void printMST(vector<int>parent , vector<vector<int>>graph)
{
int v = parent.size();
cout<<"Edge \tWeight\n";
for(int i =1;i<v;i++)
{
cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";

}
}

void prims(vector<vector<int>> graph , int v )
{
    vector<int>parent(v);
    vector<int>key(v, INT_MAX);
    vector<bool>mstSet(v , false);
    key[0] = 0;
    parent[0] = -1;

    for(int cnt =0;cnt< v - 1 ;cnt++)
    {
        int u = minKey(key , mstSet);
        mstSet[u] = true;
        for(int i=0;i<v;i++)
        {
            if(graph[u][i] && mstSet[i] == false && graph[u][i] < key[i])
            {
                parent[i] = u , key[i] = graph[u][i];
            }
        }


    }

    printMST(parent , graph);

}



int main()
{
    int v;
    cout<<"Enter no of cities: ";
    cin>>v;
    map<string , int>city_map;
    for(int i =0;i<v;i++){
    cout<<"Enter names of the " << i << "th city: ";
    string cityName;
    cin>>cityName;
    city_map[cityName] = i;
    }



    int edgeCount;
    cout<<"Enter no of edges : ";
    cin>>edgeCount;

    vector<vector<int>>graph(v , vector<int>(v,0));
    string s1 , s2;
    int val = 0;
    for(int i =0;i<edgeCount;i++)
    {
        cout<<"Enter edge "<<i<<" : \n";
        cout<<"Enter city 1 : ";
        cin>>s1;
        cout<<"Enter city 2 : ";
        cin>>s2;
        cout<<"Enter travelling cost : ";
        cin>>val;
        graph[city_map[s1]][city_map[s2]] = val;
        graph[city_map[s2]][city_map[s1]] = val;
    }

    prims(graph , v);

}