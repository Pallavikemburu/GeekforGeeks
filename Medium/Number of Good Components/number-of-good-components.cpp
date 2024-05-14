//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    void fun(vector<vector<int>>&a,int i,vector<int>&vis,int &p,int &q)
    {
        q++;
        vis[i]=1;
        p+=a[i].size();
        for(auto j:a[i])
        {
            
            if(vis[j]==0)
            {
                fun(a,j,vis,p,q);
            }
        }
    }
    int findNumberOfGoodComponent(int mm, int v, vector<vector<int>> &e) {
        // code here
        vector<vector<int>>a(v+1);
        for(auto i:e)
        {
            int p=i[0],q=i[1];
            a[p].push_back(q);
            a[q].push_back(p);
        }
        vector<int>vis(v+1,0);
        vis[0]=1;
        int ans=0;
        for(int i=1;i<=v;i++)
        {
           
            if(!vis[i])
            {
                int p=0,q=0;
                fun(a,i,vis,p,q);
                if(p==q*(q-1))
                {
                    ans++;
                }
                
            }
            
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        int res = obj.findNumberOfGoodComponent(e, v, edges);

        cout << res << endl;
    }
}

// } Driver Code Ends