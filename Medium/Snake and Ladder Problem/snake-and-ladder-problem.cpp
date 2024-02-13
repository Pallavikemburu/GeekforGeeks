//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Tevplate for C++

class Solution{
public:
    int ans=INT_MAX;
    int fun(int z,vector<pair<int,int>>&v,int c,vector<int>&dp)
    {
        if(z==30)
        {
            ans=min(ans,c);
            return 0;
        }
        if(z>30) return 1000;
        if(dp[z]!=-1) return dp[z];
        int p=1000;
        for(int i=1;i<=6;i++)
        {
            int t=z+i;
            if(v[t].first!=0 && v[t].second==0)
            {
                continue;
            }
            if(v[t].first!=0 && v[t].second!=0)
            {
               // i=v[i];
               int k=v[t].first;
               p=min(p,1+fun(k,v,c+1,dp));
            }
            p=min(p,1+fun(t,v,c+1,dp));
        }
        return dp[z]=p;
        
        
        
        /*
        int t = z + i;
        int nextPos = v[t].first;
        int isLadder = v[t].second;
        
        if (nextPos != 0) {
            if (isLadder) {
                p = min(p, 1 + fun(nextPos, v, c + 1, dp));
            } else {
                p = min(p, 1 + fun(t, v, c + 1, dp));
            }
        }  */

        //cout<<p;
        
    }
    int minThrow(int n, int a[]){
        // code here
        
       // int ans=INT_MAX,c=1;
        vector<pair<int,int>>v(39,{0,0});
        vector<int>dp(40,-1);
       // map<int,int>m;
       /* for(int i=0;i<n;i=i+2)  // ladder
        {
            v[a[i]]={a[i+1],1};
        }
        for(int i=n;i<2*n;i=i+2)  // snake
        {
            v[a[i]]={a[i+1],0};
        } */
        for(int i=0;i<2*n;i=i+2)  // ladder
        {
            if(a[i]<a[i+1])  // ladder
            v[a[i]]={a[i+1],1};
            else  // snake
            v[a[i]]={a[i+1],0};
        }
        /*for(auto i:v) 
        {
            cout<<i.first<<" "<<i.second<<"\n";
        }   */
        //cout<<ans;
       // return 0;
        return fun(1,v,0,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends