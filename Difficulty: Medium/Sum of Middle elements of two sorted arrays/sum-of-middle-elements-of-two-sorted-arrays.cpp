//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

//Position this line where user code will be pasted.
class Solution {
  public:
    int SumofMiddleElements(vector<int> &a, vector<int> &b) {
        // code here
        int n = a.size();
        int m = b.size();
        vector<int> v;
        int i = 0, j = 0;
        while (i < n && j < m && v.size() <= n) {
            if (a[i] <= b[j]) {
                v.push_back(a[i]);
                i++;
            } else {
                v.push_back(b[j]);
                j++;
            }
        }
        int x = v[n - 1];
        int y = v[n];
        return x + y;
    }
};

//{ Driver Code Starts.
//Back-end complete function template in C++

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl;
    }
}
// } Driver Code Ends