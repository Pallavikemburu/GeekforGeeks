//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/
class Solution {
  public:
    long long max_sum(int a[], int n) {
        // Your code here
        long s =0;
        long p = 0;
        for(int i=0; i<n; i++)
        {
            p += (long)i*a[i];
            s+=a[i];
        }
        long ans =p;
        for(int i=1; i<n; i++)
        {
            long c = p - (s - a[i-1]) + (long)a[i-1]*(n-1);
            p = c;
            ans = max(ans, c);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends