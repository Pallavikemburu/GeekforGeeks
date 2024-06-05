//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here
        unordered_map<int,int>mp;
        long long x=0,y=0;
        for(int i=0;i<n;i++)
        {
            mp[a[i]]++;
            x+=a[i];
        }
        for(int i=0;i<m;i++)
        {
            y+=b[i];
        }
        if((x+y)%2==1) return -1;
        x=(x+y)/2;
        for(int j=0;j<m;j++)
        {
            long long z=x-y+b[j];
            if(mp.find(z)!=mp.end()) 
            {
                return 1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends