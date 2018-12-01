#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> v[],bool vis[],int x,int n)        // recursive function to perfrom dfs
{
    
    vis[x]=true;
    cout<<x<<" ";
    
    vector<int>::iterator i;
    
    for(i=v[x].begin();i!=v[x].end();i++)
    {
        if(!vis[*i])
            dfs(v,vis,*i,n);
    }
    
}

void helper(vector<int> v[],int n)          // helper function to handle disconnected graph
{
       bool vis[n];
       memset(vis,false,sizeof(vis));
       
       for(int i=1;i<=n;i++)
       {
           if(!vis[i]&&v[i].size()>0)
           {
                
                dfs(v,vis,i,n);
                
           }
       }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m,x,y;            // n-> number of vertcies, m-> number of edges
    cin>>n>>m;
    vector<int> v[n+1];       // adjacency list to store edges
    
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    
    helper(v,n);
    
    return 0;
}
