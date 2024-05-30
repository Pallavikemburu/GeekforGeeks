//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int fun(int i, int j, string& s, string& t, vector<vector<int>>& dp, int& MOD) 
    {
        if (j < 0) 
        {
            return 1;
        }
        if (i < 0) 
        {
            return 0;
        }
        if (dp[i][j] != -1) 
        {
            return dp[i][j];
        }
        if (s[i] == t[j]) 
        {
            return dp[i][j] = (fun(i - 1, j - 1, s, t, dp, MOD) % MOD + fun(i - 1, j, s, t, dp, MOD) % MOD) % MOD;
        } 
        else 
        {
            return dp[i][j] = fun(i - 1, j, s, t, dp, MOD) % MOD;
        }
    }
  
    int countWays(string s1, string s2) {
        // code here
        int MOD = int(1e9) + 7;
        int N = s1.size(), M = s2.size();
        vector<vector<int>> dp(N, vector<int>(M, -1));
        return fun(s1.size() - 1, s2.size() - 1, s1, s2, dp, MOD);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    }
}

// } Driver Code Ends