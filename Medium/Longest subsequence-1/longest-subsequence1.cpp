//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int fun(int i, int prev, vector<int> &a, int n) 
    {
        if(i >= n)
        {
            return 0;
        }
        int p = 0;
        if(prev == -1 || abs(a[i]-a[prev]) == 1)
        {
            p = 1 + fun(i+1, i, a, n);
        }
        int q = fun(i+1, prev, a, n);
        return max(p, q);
    }
    int longestSubseq(int n, vector<int> &a) {
        // code here
        int i = 0, prev = -1;
        return fun(i, prev, a, n);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> a(n);
        Array::input(a, n);

        Solution obj;
        int res = obj.longestSubseq(n, a);

        cout << res << endl;
    }
}

// } Driver Code Ends