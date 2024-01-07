//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int fun(int m,int a[],int n)
    {
        int s=0,c=1;
        for(int i=0;i<n;i++)
        {
            s=s+a[i];
            if(s>m)
            {
                s=a[i];
                c++;
            }
            
        }
        return c;
    }
    int splitArray(int a[] ,int n, int k) {
        // code here
        int l=0,ts=0,m=0,ans=0;
        for(int i=0;i<n;i++)
        {
            ts=ts+a[i];
            l=max(l,a[i]);
        }
        ans=l;
        while(l<=ts)
        {
            m=(l+ts)/2;
            if(fun(m,a,n)>k)
            {
                l=m+1;
            }
            else
            {
                ans=m;
                ts=m-1;
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
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends