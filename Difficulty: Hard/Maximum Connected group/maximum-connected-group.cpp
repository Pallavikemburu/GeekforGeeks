//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int fun(int i,int j,int p,vector<vector<int>>& a,vector<vector<int>>&v)
    {
        if(i<0 || j<0 || i>=a.size() || j>=a.size() || a[i][j]==0 || v[i][j]!=-1) return 0;
        v[i][j]=p;
        int l=fun(i+1,j,p,a,v);
        int r=fun(i-1,j,p,a,v);
        int t=fun(i,j+1,p,a,v);
        int d=fun(i,j-1,p,a,v);
        return l+r+t+d+1;
        
    }
    int MaxConnection(vector<vector<int>>& a) {
        // code here
        int ans=0;
        int n=a.size();
        unordered_map<int,int>m;
        int pal=0;
        vector<vector<int>>v(n,vector<int>(n,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]==1 && v[i][j]==-1)
                {
                    m[(i*n+j)]=fun(i,j,(i*n+j),a,v);
                    pal=max(pal,m[(i*n+j)]);
                }
            }
        }
        // for(auto i:m) 
        // {
        //   // cout<<i.first<<" "<<i.second<<"\n";
        // }
      //  int p=0,q=0,r=0,s=0;
        vector<vector<int>>z{{-1,0},{1,0},{0,-1},{0,1}};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
               // int s=0;
                if(a[i][j]==0)
                {
                    int s=1;
                    map<int,int>beb;
                    for(int k=0;k<4;k++)
                    {
                        int x=z[k][0]+i;
                        int y=z[k][1]+j;
                        if(x<0 || x>=n || y<0 || y>=n)
                        {
                            continue;
                        }
                        else
                        {
                            //cout<<x<<" "<<y<<"\n";
                            beb[v[x][y]]=m[v[x][y]];
                          //  cout<<" "<<m[(x*n +y)]<<" ";
                        }
                    }
                    for(auto i:beb)
                    {
                        //cout<<i.first<<" "<<i.second<<"\n";
                        s=s+i.second;
                    }
                    ans=max(ans,s);
                }
              //  cout<<"\n";
                
                // if(i==0)
                // {
                //     z=i+1;
                //     p=m[(z*n +j)];
                // }
                // if(j==0)
                // {
                //     z=j+1;
                //     q=m[(i*n + z)];
                // }
                // if(j==n-1)
                // {
                    
                // }
                // if()
            }
        }
        return max(pal,ans);
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
    }
}

// } Driver Code Ends