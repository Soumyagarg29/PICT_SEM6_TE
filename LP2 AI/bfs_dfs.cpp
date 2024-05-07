#include <bits/stdc++.h>
using namespace std;
class graph 
{
    int vertices;
    int n;
    unordered_map<int,vector<int>>adjlist;
    unordered_map<string , int>city_map;
    public:
    graph() 
    {
        vertices=0;
    }
    void addedge(int i,int j) 
    {
        adjlist[i].push_back(j);
        adjlist[j].push_back(i);
    }

    void input() 
    {
        cout<<"Enter a number of vertices :- ";
        cin>>n;
        vertices=n;
        cout<<"Input"<<endl;
        for (int i=0;i<vertices;i++) 
        {
            string city;
            cout<<"Enter a city name :- ";
            cin>>city;
            city_map[city]=i;
        }
        cout<<"Enter a number of edges :- ";
        int edges;
        cin>>edges;
        for (int i=0;i<edges;i++) 
        {
            string city1,city2;
            cout<<"Enter a city1 and city2 :- ";
            cin>>city1>>city2;
            addedge(city_map[city1],city_map[city2]);
        }
    }

    int find(map<int,vector<int>>&level,int id) 
    {
        for (auto i:level) {
            for (auto j:i.second) {
                if (j==id) {
                    return i.first;
                }
            }
        }
        return -1;
    }

    void bfs(string city_name) 
    {
        int st = city_map[city_name];
        map<int,int>visited;
        map<int,vector<int>>level;

        vector<int>ans;
        queue<int>q;

        q.push(st);
        visited[st]=1;
        level[0].push_back(st);

        while (!q.empty()) 
        {
            int t=q.front();
            q.pop();
            ans.push_back(t);
            for (auto j:adjlist[t]) 
            {
                if (visited.find(j)==visited.end()) 
                {
                    visited[j]=1;
                    int val=find(level,t);
                    cout<<"visited node is :- "<<j<<" at a level "<<val+1<<endl;
                    level[val+1].push_back(j);
                    q.push(j);
                }
            }
        }
        for (auto i:ans) 
        {
            cout<<i<<" ";
        }
        cout<<endl;
        cout<<"Level wise:- "<<endl;

        for (auto i:level) {
            cout<<"level "<<i.first<<" -> ";
            for (auto j:i.second) {
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
    void dfs(int st,vector<int>&ans,map<int,int>&visited,map<int,vector<int>>&level) 
    {
        visited[st]=1;
        ans.push_back(st);

            for (auto u:adjlist[st]) {
            if (visited.find(u)==visited.end()) {
                int val=find(level,st);
                level[val+1].push_back(u);
                cout<<"Node visited :-"<<u<<", Level :-"<<val+1<<endl;
                dfs(u,ans,visited,level);
            }
        }
        }
        void dfs_print(string city_name) {
        cout<<endl;
        map<int,int>visited;
        vector<int>ans;
        int v = city_map[city_name];
        map<int,vector<int>>level;
        level[0].push_back(v);
        dfs(v,ans,visited,level);
        for (auto i:ans) {
            cout<<i<<" ";
        }
        cout<<endl;
        cout<<"Level wise:- "<<endl;
        for (auto i:level) {
            cout<<"level "<<i.first<<" -> ";
            for (auto j:i.second) {
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
};
int main() {
    graph g;

    int choice;

    char c='y';

    while (c=='y') {
        cout<<"========MENU==========\n1.Create\n2.BFS\n3.DFS\n4.Exit."<<endl;
        cout<<"Enter a choice :- ";
        cin>>choice;

        if (choice==1) {
            g.input();
        }

        else if (choice==2) {
            string st;
            cout<<"Enter a start node :- ";
            cin>>st;
            g.bfs(st);
        }

        else if (choice==3) {
            string st;
            cout<<"Enter a start node :- ";
            cin>>st;
            g.dfs_print(st);
        }

        else
        break;

        cout<<"Do you want to continue :- ";
        cin>>c;
    }

return 0;
}