//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&a)
    {
         //Your code here
        int n=a.size();
        vector<vector<int>>v(2*n-1);
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                v[i+j].push_back(a[i][j]);
            }
        }
       /* for(auto i:v)
        {
            for(auto j:i) 
            {
               // cout<<j<<" ";
            }
           // cout<<"\n"; 
        }  */
        int z=0;
        for(auto i:v)
        {
            if(z&1)
            {
                for(auto j:i)
                {
                    ans.push_back(j);
                }
            }
            else
            {
                reverse(i.begin(),i.end());
                for(auto j:i)
                {
                    ans.push_back(j);
                }
            }
            z++;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends