//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    long long pairAndSum(int n, long long a[]) {
        // code here
        long long ans=0;
        for(long long i=0;i<32;i++)
        {
            long long c=0;
            for(long long j=0;j<n;j++)
            {
                if(a[j] &(1<<i))
                {
                    c++;
                }
            }
            ans=ans+ (1<<i)*(c*(c-1))/2;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        long long Arr[N];
        for (int i = 0; i < N; i++) {
            cin >> Arr[i];
        }
        Solution ob;
        cout << ob.pairAndSum(N, Arr) << endl;
    }
    return 0;
}
// } Driver Code Ends