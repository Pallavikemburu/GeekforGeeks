//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    void fun(string s,int i,int j,int r,int c,int x,int k,int &f,vector<vector<char>>&a)
    {
        if(k==x) 
        {
           // cout<<s<<" ";
            f=1;
            return;
        }
        if(i<0 || j<0 || i>=r || j>=c || f==1 || a[i][j]=='.' ) return;
        if(a[i][j]==s[x])
        {
            char z=a[i][j];
            a[i][j]='.';
            fun(s,i+1,j,r,c,x+1,k,f,a);
            fun(s,i-1,j,r,c,x+1,k,f,a);
            fun(s,i,j-1,r,c,x+1,k,f,a);
            fun(s,i,j+1,r,c,x+1,k,f,a);
            fun(s,i+1,j+1,r,c,x+1,k,f,a);
            fun(s,i+1,j-1,r,c,x+1,k,f,a);
            fun(s,i-1,j+1,r,c,x+1,k,f,a);
            fun(s,i-1,j-1,r,c,x+1,k,f,a);
            a[i][j]=z;
        }
        else
        {
            return;
        }
        
    }
	vector<string> wordBoggle(vector<vector<char> >& a, vector<string>& d) {
	    // Code here
	    vector<string>ans;
	    int r=a.size(),c=a[0].size();
	    for(auto k:d)
	    {
	        for(int i=0;i<r;i++)
	        {
	            int f=0;
	            for(int j=0;j<c;j++)
	            {
	                if(a[i][j]==k[0] && f==0)
	                {
	                    if(k.size()==1)
	                    {
	                        f=1;
	                    }
	                    else
	                    {
	                        fun(k,i,j,r,c,0,k.size(),f,a);
	                    }
	                    //cout<<f<<" ";
	                    if(f==1)
	                    {
	                        break;
	                    }
	                }
	            }
	            if(f==1)
	            {
	               ans.push_back(k);
	               break;
	            }
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
        int N;
        cin >> N;
        vector<string> dictionary;
        for (int i = 0; i < N; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int R, C;
        cin >> R >> C;
        vector<vector<char> > board(R);
        for (int i = 0; i < R; i++) {
            board[i].resize(C);
            for (int j = 0; j < C; j++) cin >> board[i][j];
        }
        Solution obj;
        vector<string> output = obj.wordBoggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends