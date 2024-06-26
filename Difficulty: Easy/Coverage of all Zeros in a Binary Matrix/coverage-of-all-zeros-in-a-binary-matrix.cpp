//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int findCoverage(vector<vector<int>>& a) {
        // Code here
        int sum=0;
        int  n=a.size(),m=a[0].size();
        vector<int>r={-1,0,1,0};
        vector<int>c={0,1,0,-1};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==0)
                {
                   for(int k=0;k<4;k++)
                   {
                       int nr=i+r[k],nc=j+c[k];
                       if(nr>=0 && nr<n &&nc>=0 && nc<m && a[nr][nc]) sum++;
                   } 
                }
            }
        }
        return sum;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        int ans = obj.findCoverage(matrix);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends