//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
    void fun1(vector<int> arr, vector<int>&p)
    {
        stack<int> st;
        for(int i=0;i<arr.size();i++)
        {
            if(st.empty())
            {
                p.push_back(0);
            }
            else if(!st.empty() && st.top() >= arr[i])
            {
                while(!st.empty() && st.top() >= arr[i]) 
                {
                    st.pop();
                }
                if(st.empty()) p.push_back(0);
                else p.push_back(st.top());
            }
            else if(!st.empty() && st.top() < arr[i]) p.push_back(st.top());
            st.push(arr[i]);
        }
    }
    void fun2(vector<int> arr, vector<int>&q)
    {
        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--)
        {
            if(st.empty())
            {
                q.push_back(0);
            }
            else if(!st.empty() && st.top() >= arr[i])
            {
                while(!st.empty() && st.top() >= arr[i])
                {
                    st.pop();
                }
                if(st.empty()) q.push_back(0);
                else q.push_back(st.top());
            }
            else if(!st.empty() && st.top() < arr[i]) q.push_back(st.top());
            st.push(arr[i]);
        }
    }
    int findMaxDiff(vector<int> &a) {
        // Your code here
        int n = a.size();
        vector<int> p;
        vector<int> q;
        fun1(a,p);
        fun2(a,q);
        reverse(q.begin(),q.end());
        int maxi = INT_MIN;
        for(int i=0;i<a.size();i++)
        {
            maxi = max(maxi,abs(p[i]-q[i]));
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends