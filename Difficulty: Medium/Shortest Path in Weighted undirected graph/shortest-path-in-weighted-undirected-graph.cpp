//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        if(m==0) 
        {
            return {-1};
        }
        vector<vector<pair<int,int>>>a(n+1);
        vector<int>ans;
        vector<int>p(n+1);
        vector<int>d(n+1,INT_MAX);
        for(auto i:edges)
        {
            int u=i[0],v=i[1],w=i[2];
            a[u].push_back({v,w});
            a[v].push_back({u,w});
        }
        for(int i=1;i<=n;i++)
        {
            p[i]=i;
        }
        queue<pair<int,int>>q;
        // for(int i=0;i<a[0].size();i++)
        // {
        //     //int u=a[0]
        //     q.push(a[0][i]);
        // }
        // ans.push_back(-1);
        // return ans;
        q.push({1,0});
        d[1]=0;
        while(!q.empty())
        {
            auto fr=q.front();
            q.pop();
            int node=fr.first,wt=fr.second;
            for(auto i:a[node])
            {
                int x=i.first,y=i.second;
                if(d[x]>y+wt)
                {
                    p[x]=node;
                    d[x]=y+wt;
                    q.push({x,d[x]});
                }
            }
            
        }
        //for(auto i:d) cout<<i<<" ";
        if(d[n]==INT_MAX) return {-1};
        int r=n;
      //  for(auto i:p) cout<<i<<" ";
        //ans.push_back(1);
        while(r!=p[r])
        {
            ans.push_back(r);
            r=p[r];
        }
        ans.push_back(1);
        ans.push_back(d[n]);
        reverse(ans.begin(),ans.end());
       // for(auto i:ans) cout<<i<<" ";
       // for(auto i:ans) cout<<i<<" ";
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends