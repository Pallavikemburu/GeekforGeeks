//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> recamanSequence(int n){
        // code here
        unordered_map<int,int>m;
        vector<int>ans;
        ans.push_back(0);
        m[0]=1;
        for(int i=1;i<n;i++)
        {
            int z=ans[i-1]-i;
            if(z<0 || m[z]==1)
            {
                z=ans[i-1]+i;
            }
            m[z]=1;
            ans.push_back(z);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends