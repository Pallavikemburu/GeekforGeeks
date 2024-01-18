//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int min_sprinklers(int a[], int n)
    {
        // code here
        vector<int> z(n,-1);
        for(int i = 0;i<n;i++)
        {
            if(a[i] != -1)
            {
                int k = max(0,i-a[i]);
                int b = min(n-1,i+a[i]);
                for(int j = k;j<=b;j++)
                {
                    z[j] = max(z[j],b);
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(z[i] == -1)
            {
                return -1;
            }
            if(i<=z[i])
            {
                ans++;
                i = z[i];
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
        int n;
        cin>>n;
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}

// } Driver Code Ends