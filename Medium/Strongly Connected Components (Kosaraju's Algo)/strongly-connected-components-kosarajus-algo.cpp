//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void fun(int i,vector<vector<int>>&a, vector<int>&vis, vector<int>&dfs, int v)
	{
	    vis[i]=1;
	    for(auto j:a[i])
	    {
	        if(vis[j]==0)
	        {
	            fun(j,a,vis,dfs,v);
	        }
	    }
	    dfs.push_back(i);
	}  
    int kosaraju(int v, vector<vector<int>>& a)
    {
        //code here
        vector<vector<int>>radj(v+1);
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<a[i].size();j++) 
            {
                radj[a[i][j]].push_back(i);
            }
            //cout<<j<<" ";
            //cout<<"\n";
            //int p=i[0],q=i[1];
           // adj[p].push_back(q);
        }
       /* for(auto i:radj)
        {
            for(auto j:i) cout<<j<<" ";
            cout<<"\n";
        }   */
        vector<int>vis(v,0);
        vector<int>rvis(v,0);
        vector<int>dfs;
        for(int i=0;i<v;i++)
        {
            if(vis[i]==0)
            {
                fun(i,a,vis,dfs,v);
            }
        }
        //for(auto i:dfs) cout<<i<<" ";
        int ans=0;
        vector<int>z;
       /* for(auto i:radj)
        {
            for(auto j:i)
            {
                cout<<j<<" ";
            }
            cout<<"\n";
        }  */
        reverse(dfs.begin(),dfs.end());
        for(auto i:dfs)
        {
            if(rvis[i]==0)
            {
                ans++;
                //cout<<i<<" ";
                fun(i,radj,rvis,z,v);
            }
        }
        //for(auto i:z) cout<<i<<" ";
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends