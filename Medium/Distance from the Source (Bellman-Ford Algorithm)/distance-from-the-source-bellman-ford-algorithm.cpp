//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int v, vector<vector<int>>& a, int s) {
        // Code here
        vector<int>ans(v,100000000);
        ans[s]=0;
        for(int i=0;i<v-1;i++)
        {
            for(auto edge : a)
            {
                int u=edge[0];
                int v=edge[1];
                int w=edge[2];
                if(ans[u]!=100000000 && ans[v] > ans[u]+w)
                {
                    ans[v]=ans[u]+w;
                }
            }
        }
        for(auto edge : a)
        {
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            if(ans[u]!=100000000 && ans[v] > ans[u]+w)
            {
                return {-1};
               // ans[v]=ans[u]+w;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends