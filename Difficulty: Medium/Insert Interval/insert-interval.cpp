//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &a,vector<int> &b) {
        // code here
        vector<vector<int>>ans;
        a.push_back({b[0],b[1]});
        sort(a.begin(),a.end());
        int st=a[0][0],end=a[0][1];
        for(int i=1;i<a.size();i++)
        {
            if((end>=a[i][0] && end<=a[i][1]) || (end>a[i][1])){
                st=min(st,a[i][0]);
                end=max(end,a[i][1]);
            }
            else
            {
                ans.push_back({st,end});
                st=a[i][0];
                end=a[i][1];
            }
        }
        ans.push_back({st,end});
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
        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        vector<int> newInterval(2);
        cin >> newInterval[0] >> newInterval[1];

        Solution obj;
        vector<vector<int>> ans = obj.insertInterval(intervals, newInterval);
        cout << "[";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[" << ans[i][0] << ',' << ans[i][1] << ']';
            if (i != (ans.size() - 1))
                cout << ",";
        }
        cout << "]" << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends