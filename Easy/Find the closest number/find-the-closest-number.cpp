//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        // Complete the function
        int mini = INT_MAX;
        for(int i=0;i<n;i++)
        {
            mini = min(mini, abs(k-arr[i]));
        }
        //cout<<mini<<endl;
        int ans =0;
        for(int i=0;i<n;i++)
        {
            if(mini ==abs(k-arr[i]))
            {
               ans = max(ans,arr[i]);
            }
        }
        return ans;
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends