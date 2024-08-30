//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    bool isvalid( vector<vector<int>>&a,int p,int q,int n)
    {
        for(int i=0;i<n;i++)
        {
            // if(a[p][i]==1) return false;
            if(a[i][q]==1) return false;
        }
        int r=p-1,c=q-1;
        while( r>=0 && c>=0)
        {
            if(a[r][c]) return false;
            r--;
            c--;
        }
        r=p-1,c=q+1;
        while( r>=0 && c<n)
        {
            if(a[r][c]) return false;
            r--;
            c++;
        }
        return true;
    }
    void fun( vector<vector<int>>&a,int n,int p,vector<vector<int>>&ans)
    {
        if(p==n)
        {
            vector<int>t;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(a[i][j]==1)
                    {
                        t.push_back(j+1);
                    }
                }
            }
            ans.push_back(t);
            return;
        }
        for(int j=0;j<n;j++)
        {
            if(isvalid(a,p,j,n))
            {
                a[p][j]=1;  
                fun(a,n,p+1,ans);
                a[p][j]=0;
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>>board(n,vector<int>(n,0));
        vector<vector<int>>ans;
        fun(board,n,0,ans);
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends