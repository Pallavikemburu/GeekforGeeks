//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool fun(int k, vector<int> a[],vector<int>&vis,int z) 
    {
        queue<pair<int,int>>q;
        q.push({k,z});
        vis[k]=1;
        while(!q.empty())
        {
            int n=q.front().first;
            int p=q.front().second;
            q.pop();
            for(auto i:a[n])
            {
                if(vis[i]==0)
                {
                    vis[i]=1;
                    q.push({i,n});
                }
                else
                {
                    if(p!=i)
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int n, vector<int> a[]) 
    {
        vector<int>vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                if(fun(i,a,vis,-1))
                return true;
            }
        }
        return false;
    }
    
 /* bool dfs(int i,vector<int>a[],vector<int>&vis,int p)
  {
      vis[i]=1;
      for(auto it:a[i])
      {
          if(vis[it]!=1)
          {
              //vis[it]=1;
              if(dfs(it,a,vis,i)) return true;
          }
          else
          {
              if(it!=p) return true;
          }
      }
      return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int n, vector<int> a[]) {
        // Code here
        
        vector<int>vis(n,0);
        //bool ans;
        for(int i=0;i<n;i++)
        {
            if(vis[i]!=1)
            {
                if(dfs(i,a,vis,-1))
                return true;
            }
        }
        return false;
        
    }  */
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends