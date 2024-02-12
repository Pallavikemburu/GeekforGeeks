//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long sequence(int n){
        // code here
        int i=1,j=1;
        int mod=1e9+7;
        long long ans=0;
        while(i<=n)
        {
            int k=1;
            long long z=1;
            while(k<=i)
            {
                z=(z*j)%mod;
                j++;
                k++;
            }
            ans=ans+z;
            ans=ans%mod;
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends