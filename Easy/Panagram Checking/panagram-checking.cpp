//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string s) {
        // your code here
        vector<int>v(26,0);
        for(auto i:s)
        {
            int a=i-'a';
            int b=i-'A';
           // cout<<a<<" "<<b<<"\n";
            if((a>=0 && a<26))
            {
                v[a]++;
            }
            else if((b>=0 && b<26))
            {
                v[b]++;
            }
        }
        for(auto i:v)
        {
            if(i==0) return false;
        }
        return true;
    }

};

//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string s;
        getline(cin, s);
        Solution obj;
        if (obj.checkPangram(s) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}

// } Driver Code Ends