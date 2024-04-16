//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int minimizeDifference(int n, int k, vector<int> &arr) {
        // code here
       int ans = INT_MAX;
       vector<int>p(n),q(n);
       vector<int>x(n),y(n);
       p[0] = INT_MIN;
       q[0] = INT_MAX;
       x[n-1] = INT_MIN;
       y[n-1] = INT_MAX;
       for(int i = 1; i<n; i++)
       {
           p[i] = max(p[i-1], arr[i-1]);
           q[i] = min(q[i-1], arr[i-1]);
       }
       for(int i = n-2; i>=0; i--)
       {
           x[i] = max(x[i+1], arr[i+1]);
           y[i] = min(y[i+1], arr[i+1]);
       }
       int i = 0;
       for(int j = 0; j<n; j++)
       {
           if(j-i+1 == k)
           {
               ans = min(ans, max(p[i], x[j]) - min(q[i], y[j]));
               i++;
           }
       }
       return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        int res = obj.minimizeDifference(n, k, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends