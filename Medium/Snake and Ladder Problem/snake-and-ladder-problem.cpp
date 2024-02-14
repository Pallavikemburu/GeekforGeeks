//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int n, int a[]){
        // code here
       vector<pair<int,int>>v(39,{0,0});
       vector<int>vis(31,-1);
       for(int i=0;i<2*n;i=i+2)  
        {
            if(a[i]<a[i+1])  // ladder
            v[a[i]]={a[i+1],1};
            else             // snake
            v[a[i]]={a[i+1],0};
        }
        queue<pair<int,int>>q;
        q.push({1,0});
        while(!q.empty())
        {
            auto z=q.front();
           // cout<<z.first<<" ";
            q.pop();
            for(int i=1;i<=6;i++)
            {
                int p=z.first+i;
               // cout<<p<<" ";
                if(p==30)
                    return z.second+1;
                if(vis[p]==-1)
                {
                   // cout<<p<<" ";
                    if(v[p].first!=0 && v[p].second==0)
                    {
                        continue;
                    }
                    if(v[p].first!=0 && v[p].second!=0)
                    {
                        vis[v[p].first]=1;
                        q.push({v[p].first,z.second+1});
                    }
                    else
                    {
                        vis[p]=1;
                        q.push({p,z.second+1});
                    }
                }
            }
        }
        return -1;
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