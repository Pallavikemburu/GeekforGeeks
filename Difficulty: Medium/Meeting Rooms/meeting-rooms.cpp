//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // Your Code Here
        vector<pair<int,int>>v;
        for(int i=0; i<arr.size(); i++) 
        {
              v.push_back({arr[i][0],arr[i][1]});
        }
        sort(v.begin(), v.end(), [](const pair<int, int> &p1, const pair<int, int> &p2) {
        return p1.first < p2.first; });
        for(int i=0; i<v.size()-1; i++) 
        {
              if(v[i].second>v[i+1].first) return false;
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        cin.ignore();
        Solution obj;
        bool ans = obj.canAttend(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends