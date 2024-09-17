//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(vector<int> &a, int k) {
        // code here
        int n = a.size();
        sort(a.begin(), a.end());
        int diff = a[n-1]-a[0];
        int maxi,mini;
        for(int i=1;i<n;i++) 
        {
            if((a[i]-k)<0) 
            {
                continue;
            }
            maxi = max(a[i-1]+k, a[n-1]-k);
            mini = min(a[0]+k,a[i]-k);
            diff = min(diff,maxi-mini);
        }
        return diff;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, k;
        cin >> k;
        cin.ignore();
        vector<int> a, b, c, d;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution ob;
        auto ans = ob.getMinDiff(a, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends