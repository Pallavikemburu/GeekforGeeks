//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &a, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &a[i]);
        }
    }

    template <class T>
    static void print(vector<T> &a) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    long long maxTip(int n, int x, int y, vector<int> &a, vector<int> &b) {
        // code here
        priority_queue<pair<int, pair<int, int>>> p;
        for(int i = 0; i < n; i++)
        {
            p.push({abs(a[i]-b[i]), {a[i], b[i]}});
        }
        long long ans = 0, ac = 0, bc = 0;
        while(!p.empty())
        {
            if((p.top().second.first >= p.top().second.second && ac < x) || (bc >= y))
            {
                ans += p.top().second.first;
                ac++;
            }
            else
            {
                ans += p.top().second.second; 
                bc++;
            }
            p.pop();
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        vector<int> arr(n);
        Array::input(arr, n);

        vector<int> brr(n);
        Array::input(brr, n);

        Solution obj;
        long long res = obj.maxTip(n, x, y, arr, brr);

        cout << res << endl;
    }
}

// } Driver Code Ends