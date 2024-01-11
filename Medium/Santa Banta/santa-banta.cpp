//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
public:
    
    vector<int>primes;
    void precompute()
    {
        vector<int>s(1000001,1);
        s[0]=0;
        s[1]=0;
        int n=1000000+1;
        for(int i=2;i*i<=n;i++)
        {
            if(s[i]==1)
            {
                for(int j=i*i;j<=n;j+=i)
                {
                    s[j]=0;
                }
            }
        }
        for(int i=2;i<=n;i++)
        {
        	if(s[i]==1) primes.push_back(i);
	    }
    }
    void dfs(vector<vector<int>>&a,vector<int>&vis,int i,int &c)
    {
	    vis[i]=1;
	   // cout<<node<<" ";
	    for(auto it:a[i])
	    {
		    if(!vis[it])
		    {
		       // cout<<c<<" ";
			    dfs(a,vis,it,++c);
		    }
	    }
    
    }
    int helpSanta(int n, int z, vector<vector<int>> &g)
    {
        // Code here
        if(z==0) return -1;
        vector<vector<int>>a(n+1);
        int m=0;
        for(auto i:g)
        {
            int f=i[0];
            int s=i[1];
            a[f].push_back(s);
            a[s].push_back(f);
        }
        vector<int>vis(n+1,0);
        for(int i=1;i<=n;i++)
        {
            
            if(vis[i]==0)
            {
               int c=0;
               dfs(a,vis,i,c);
               //cout<<"\n";
               //cout<<c<<" ";
               m=max(c,m);
            }
        }
        return primes[m];
    }
};

//{ Driver Code Starts.

int main(){
	int t;cin>>t;
	Solution ob;
	ob.precompute();
	while(t--){
        int n,e,u,v;
        cin>>n>>e;
        vector<vector<int>> g;
        
		for(int i = 0; i < e; i++)
		{
			cin>>u>>v;
			g.push_back({u, v});
// 			g[u].push_back(v);
// 			g[v].push_back(u);
		}
		cout << ob.helpSanta(n, e, g) << endl;
		
	}
}



// } Driver Code Ends