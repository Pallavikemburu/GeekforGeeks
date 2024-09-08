//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of aay

class Solution {
  public:
    int minJumps(vector<int>& a) {
        // Your code here
        int n = a.size();
        if(a[0] == 0)   return -1;
        int ans = 0,  z= 0, t = 0;
        for(int i = 0; i < n - 1; i++)
        {
             z= max(z, i + a[i]);
            if(i == t)
            {
                t =z ;
                ans++;
            }
        }
        if(t < n - 1)   return -1;
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends