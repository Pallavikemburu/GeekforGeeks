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
    vector<int> getPrimes(int n) {
        // code here
        vector<int> ans;
        if(n<=3)    return {-1,-1};
        set<int> p;
        p.insert(2);
        p.insert(3);
        p.insert(5);
        p.insert(7);
        for (int i = 11; i < n; i += 2)
        {
            bool z = true;
            for (int j = 3; j * j <= i; j += 2) 
            {
                if (i % j == 0)
                {
                    z = false;
                    break;
                }
            }
            if (z)
            {
                p.insert(i);
            }
        }
        for (int i : p) 
        {
            int q = n - i;
            if (p.count(q))
            {
                ans.push_back(i);
                ans.push_back(q);
                return ans;
            }
        }
        return {-1,-1};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends