//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

bool isSubSequence(vector<int> &v1, vector<int> &v2) {
    int m = v2.size();
    int n = v1.size();
    int j = 0; // For index of v2

    // Traverse v1 and v2
    for (int i = 0; i < n && j < m; i++) {
        if (v1[i] == v2[j]) {
            j++;
        }
    }
    return (j == m);
}


// } Driver Code Ends
// Function to find three numbers in the given aay
// such that a[smaller[i]] < a[i] < a[greater[i]]

class Solution {
  public:
    vector<int> find3Numbers(vector<int> &a) {
        // Code here
        int n = a.size();
        if (n < 3) return {};
        vector<int> p(n), q(n);
        p[0] = a[0];
        for (int i = 1; i < n; i++) 
        {
            p[i] = min(p[i - 1], a[i]);
        }
        q[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--) 
        {
            q[i] = max(q[i + 1], a[i]);
        }
        for (int i = 1; i < n - 1; i++) 
        {
            if (a[i] > p[i] && a[i] < q[i]) 
            {
                return {p[i], a[i], q[i]};
            }
        }
        return {};
    }
};

//{ Driver Code Starts.

// Driver program to test above function
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution obj;
        auto res = obj.find3Numbers(arr);
        // wrong format output
        if (!res.empty() and res.size() != 3) {
            cout << -1 << "\n";
        }

        if (res.empty()) {
            cout << 0 << "\n";
        } else if ((res[0] < res[1] and res[1] < res[2]) and isSubSequence(arr, res)) {
            cout << 1 << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}
// } Driver Code Ends