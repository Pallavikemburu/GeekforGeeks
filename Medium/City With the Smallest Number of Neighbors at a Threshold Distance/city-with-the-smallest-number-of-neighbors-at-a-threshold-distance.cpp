//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
        int fun(vector<vector<pair<int,int>>>&a,int i,int t,int n)
        {
            vector<int>d(n,INT_MAX);
            d[i]=0;
            queue<int> q;
            q.push(i);
            int c=0;
            while(!q.empty())
            {
                int z= q.front();
                q.pop();
                for(auto i : a[z])
                {
                    int x= i.first;
                    int y= i.second;
                    if(d[x]> d[z]+y)
                    {
                       d[x]= d[z]+y;
                       q.push(x);
                    }
               }
            }
            for(int i=0;i<n;i++)
            {
                if(d[i]!=0)
                {
                    if(d[i]<=t)
                    {
                        c++;
                    }
                }
            }
            return c;
            
            
        /*queue<pair<int,int>>q;
        q.push({i,0});
        int c=0;
        vector<int>vis(n,0);
        vis[i]=1;
        while(!q.empty())
        {
            c++;
            auto z=q.front();
            q.pop();
            int x=z.first,y=z.second;
          //  cout<<x<<" "<<y<<endl;
            for(auto i:a[x])
            {
                if(t-i.second>=0 && vis[i.first]==0)
                {
                    vis[i.first]=1;
                    q.push({i.first,t-i.second});
                   // cout<<i.first<<" ";
                }
            } 
        }
        return c; */
    }
    
    int findCity(int n, int m, vector<vector<int>>& v, int t) {
        // Your code here
        vector<vector<pair<int,int>>>a(n);
        int c=INT_MAX,ans=0;
        for(auto i:v)
        {
            int p=i[0],q=i[1],r=i[2];
            a[p].push_back({q,r});
            a[q].push_back({p,r});
        }
        for(int i=0;i<n;i++)
        {
            int z=fun(a,i,t,n);
           // cout<<z<<" ";
            if(z<=c)
            {
                c=z;
                ans=i;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends