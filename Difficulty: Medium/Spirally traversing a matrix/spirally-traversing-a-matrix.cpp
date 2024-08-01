//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > m) 
    {
        // code here 
        int p=0,q=m.size()-1,r=0,s=m[0].size()-1,c=0,z=((q+1)*(s+1)),i,j,n=z;
        vector<int>v;
        while(c<z)
        {
            for(i=r;i<=s;i++)
            {
                if(c>=n) break;
                v.push_back(m[p][i]);
                c++;
            }
            p++;
            for(i=p;i<=q;i++)
            {
                if(c>=n) break;
                v.push_back(m[i][s]);
                c++;
                //if(c>=n) break;
            }
            s--;
            for(i=s;i>=r;i--)
            {
                if(c>=n) break;
                v.push_back(m[q][i]);
                c++;
                //if(c>=n) break;
            }
            q--;
            for(i=q;i>=p;i--)
            {
                if(c>=n) break;
                v.push_back(m[i][r]);
                c++;
                //if(c>=n) break;
            }
            r++;
        }
        //v.pop_back();
        return v;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends