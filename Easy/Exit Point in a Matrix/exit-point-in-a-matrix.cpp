//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& a) {
        // Code here
        int i=0,j=0,c=0,f=true;
        while (i<n)
        {
            while(j<m)
            {
               if (c%4==0)
               {
                   if (a[i][j]==0)
                   {
                       j++;
                   }
                   else
                   {
                       c++;
                       a[i][j]=0;
                       i++;
                   }
               }
               else if (c%4==1)
               {
                   if (a[i][j]==0)
                   {
                       i++;
                   }
                   else 
                   {
                        c++;
                        a[i][j]=0;
                        j--;
                   }
               }
               else if (c%4==2)
               {
                   if (a[i][j]==0)
                   {
                      j--;
                   }
                   else 
                   {
                       c++;
                       a[i][j]=0;
                       i--;
                   }
               }
               else if (c%4==3)
               {
                   if (a[i][j]==0)
                   {
                      i--;
                   }
                   else 
                   {
                        c++;
                        a[i][j]=0;
                        j++;
                   }
                }
                 if (i<0 || i>=n || j<0 || j>=m )
                 {
                     f=false;
                     break;
                 }
            }
            if (f==false)   break;
        }
        if (i<0)   
        {
            i++;
        }
        if (i==n)  
        {
            i--;
        }
        if (j<0)  
        {
            j++;
        }
        if (j==m)   
        {
            j--;
        }
        return {i,j};
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
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends