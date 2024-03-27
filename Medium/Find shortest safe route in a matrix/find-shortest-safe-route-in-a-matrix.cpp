//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    bool ok(vector<vector<int>> &a,int i,int j,int r,int c)
    {
        if(i<0 || i>=r || j<0 || j>=c) 
        {
            return false;
        }
        if(a[i][j]==0) 
        {
            return false;
        }
        if(i-1>=0 && a[i-1][j]==0) 
        {
            return false;
        }
        if(i+1<r && a[i+1][j]==0) 
        {
            return false;
        }
        if(j-1>=0 && a[i][j-1]==0)
        {
            return false;
        }
        if(j+1<c && a[i][j+1]==0)
        {
            return false;
        }
        return true;
    }
    
    int fun(vector<vector<int>>&a,int i,int j,int r,int c,vector<vector<int>>&dp)
    {
        if(j==c-1) return 0;
        if(j>=c)
        {
            return 10000;
        }
        dp[i][j]=1;
        int t=10000,d=10000,s=10000;
        if(ok(a,i-1,j,r,c))
        {
            if(!dp[i-1][j])
            {
                t=1+fun(a,i-1,j,r,c,dp);
            }
        }
        if(ok(a,i,j+1,r,c))
        {
            if(!dp[i][j+1])
            {
                s=1+fun(a,i,j+1,r,c,dp);
            }
        }
        if(ok(a,i+1,j,r,c))
        {
            if(!dp[i+1][j])
            {
                d=1+fun(a,i+1,j,r,c,dp);
            }
        }
        dp[i][j]=0;
        return min(t,min(d,s));
        
    }
    int findShortestPath(vector<vector<int>> &a)
    {
       // code here
       int r=a.size(),c=a[0].size();
       int ans=INT_MAX;
       vector<vector<int>>dp(r+1,vector<int>(c+1,0));
       for(int i=0;i<r;i++)
       {
            if(ok(a,i,0,r,c))
            {
                ans=min(ans,fun(a,i,0,r,c,dp));
            }
       }
       if(ans>=10000)
       {
           return -1;
       }
       return ans+1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends