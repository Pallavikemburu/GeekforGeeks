//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  
    long long fun(int i,int j,int z,int n,vector<vector<vector<long long >>>&dp)
    {
        long long pall=0;
        if(i<0 || j<0 || i>3 || j>2 || (i==3 && j==0) || (i==3 && j==2))
        {
            return 0;
        }
        if(z==n)
        {
            return 1;
        }
        if(dp[i][j][z]!=0) return dp[i][j][z];
        pall=pall+fun(i,j,z+1,n,dp)
             +fun(i+1,j,z+1,n,dp)
             +fun(i,j+1,z+1,n,dp)
             +fun(i,j-1,z+1,n,dp)
             +fun(i-1,j,z+1,n,dp);
             
        return dp[i][j][z]=pall;
        
    }
    long long getCount(int n) {
        // Your code goes here
        map<int,pair<int,int>>m;
        m[0]={3,1};
        m[1]={0,0};
        m[2]={0,1};
        m[3]={0,2};
        m[4]={1,0};
        m[5]={1,1};
        m[6]={1,2};
        m[7]={2,0};
        m[8]={2,1};
        m[9]={2,2};
        long long  s=0;
        vector<vector<vector<long long >>>dp(4,vector<vector<long long >>(3,vector<long long>(25,0)));
        for(int i=0;i<=9;i++)
        {
            pair<int,int>z=m[i];
            int p=z.first,q=z.second;
            s=s+fun(p,q,1,n,dp);
        }
        return s;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends