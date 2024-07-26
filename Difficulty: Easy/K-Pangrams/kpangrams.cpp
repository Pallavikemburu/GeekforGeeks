//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string s, int k) {
        // code here
        vector<int>v(26);
        for(auto i:s)
        {
            if(i==' ') continue;
            v[i-'a']++;
        }
        int ex=0,c=0;
        for(auto i:v)
        {
            if(i==1)
            {
                c++;
            }
            else if(i>1)
            {
                c++;
                ex+=i-1;
            }
        }
        int z=26-c;
        if(ex<k) k=ex; 
     //   cout<<z<<" "<<k<<"\n";
        if(z<=k) return true;
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends