//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void fun(int i,int j,vector<vector<int>> &a, int n,vector<string>&ans,string temp)
    {
        if(i<0 || j<0 || j>=n || i>=n) return;
        if(a[i][j]==0 || a[i][j]==2) return;
        if(i==n-1 && j==n-1) 
        {
            ans.push_back(temp);
            //cout<<temp<<"\n";
            return;
        }
        a[i][j]=2;
        //temp.push_back('D');
        fun(i+1,j,a,n,ans,temp+'D');
        //temp.pop_back();
        //temp.push_back('L');
        fun(i,j-1,a,n,ans,temp+'L');
        //temp.pop_back();
        //temp.push_back('R');
        fun(i,j+1,a,n,ans,temp+'R');
        //temp.pop_back();
        //temp.push_back('U');
        fun(i-1,j,a,n,ans,temp+'U');
        a[i][j]=1;
       // temp.pop_back();
    }
    vector<string> findPath(vector<vector<int>> &m) {
        // Your code goes here
        int n=m.size();
        if(m[n-1][n-1]==0) return {"-1"};
        if(m[0][0]==0) return {"-1"};
        vector<string>ans;
        string temp="";
        fun(0,0,m,n,ans,temp);
       // if(ans.size()==0) return {"-1"};
        return ans;
    }
};

    



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends