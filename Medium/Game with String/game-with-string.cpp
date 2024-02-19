//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        priority_queue<int>pq;
        int ans=0;
        map<int,int>m;
        for(auto i:s)
        {
            m[i]++;
        }
        for(auto i:m)
        {
            pq.push(i.second);
        }
        while(!pq.empty() && k)
        {
            k--;
            int z=pq.top();
            pq.pop();
            pq.push(z-1);
        }
        while(!pq.empty())
        {
            int z=pq.top();
            pq.pop();
            ans=ans+(z*z);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends