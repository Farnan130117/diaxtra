#include <iostream>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;
vector <int> edge[100];
int cost[100][100];
int d[100];
int parent[100];
void shortest_path(int n,int src)
{

 for(int i=1;i<=n;i++)
 {
     d[i]=10000;

 }
     queue <int> q;
     q.push(src);
     d[src]=0;
     while(!q.empty())
     {
         int u=q.front();

         for( int i=0;i<edge[u].size();i++)
         {
             int v=edge[u][i];
             if(d[u]+cost[u][v]<d[v])
             {
                  parent[v]=u;
                  d[v]=d[u]+cost[u][v];
                 q.push(v);
             }
         }
         q.pop();
     }
 }

int main()
{
    int node,ed;
    cin>>node>>ed;
    int e1,e2,amount;
    for(int i=1;i<=ed;i++)
    {
        cin>>e1>>e2>>amount;
        edge[e1].push_back(e2);
        edge[e2].push_back(e1);
        cost[e1][e2]=amount;
        cost[e2][e1]=amount;
    }

    shortest_path(node,1);

    cout<<d[node];

   int u=node;
    cout <<endl<< "\n\n Node no "<<u << "'s  shortest path list: " <<endl;
    while(u!=1)
    {
        cout <<"Node :" <<parent[u] <<endl;
        u=parent[u];
    }
    return 0;
}
