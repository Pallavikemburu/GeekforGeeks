//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        int fun(vector<vector<int>>&adj, vector<int>&degree,int n,int m,int i)
        {
            if(i>n)
            {
                if(m==0) return 0;
                return 100;
            }
            int p=0,np=0;
            for(auto j:adj[i])
            {
                degree[j]--;
            }
            p=1+fun(adj,degree,n,m-degree[i],i+1);
            for(auto j:adj[i])
            {
                degree[j]++;
            }
            np=fun(adj,degree,n,m,i+1);
            return min(p,np);
        }
        int vertexCover(int n, vector<pair<int, int>> &e)
        {
            // code here
            vector<int>degree(n+1,0);
            vector<vector<int>>adj(n+1);
            int ans=0,m=e.size();
            for(auto i:e)
            {
                int x=i.first;
                int y=i.second;
                adj[x].push_back(y);
                adj[y].push_back(x);
            }
            for(int i=0;i<=n;i++)
            {
                degree[i]=adj[i].size();
            }
           /* for(auto i:degree)
            {
                cout<<i<<" ";
            }  */
            
            return fun(adj,degree,n,m,1);
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>> edges;
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            edges.push_back({a,b});
        }
        Solution s;
        cout<<s.vertexCover(n,edges)<<endl;
    }
    return 0;
}
// } Driver Code Ends