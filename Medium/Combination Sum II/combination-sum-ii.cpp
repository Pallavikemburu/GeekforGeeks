//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    void fun(vector<int> &a, int z, int k, vector<int> &t, vector<vector<int>> &ans)
    {
        if(z == 0)
        {
            ans.push_back(t);
            return;
        }
        for(int i=k; i<a.size(); i++)
        {
            if(i>k && a[i] == a[i-1])   continue;
            else if (z < a[i])   break;
            t.push_back(a[i]);
            fun(a, (z - a[i]), (i+1), t, ans);
            t.pop_back();
        }
    }
    vector<vector<int>> CombinationSum2(vector<int> a,int n,int k)
    {
        vector<vector<int>> ans;
        vector<int> t;
        sort(a.begin(), a.end());
        fun(a, k, 0, t, ans);
        return ans;
    }
    // void fun(vector<int> a,int n,int k,vector<int>&v,set<vector<int>>&ans,int i)
    // {
    //     if(i>=n)
    //     {
    //         // cout<<"hi";
    //         if(k==0)
    //         {
    //             //if(m.find(v)==m.end())
    //             ans.insert(v);
    //             //m[v]++;
    //         }
    //         return;
    //     }
    //     if(k==0)
    //     {
    //         //cout<<"hi";
    //         //if(m.find(v)==m.end())
    //         ans.insert(v);
    //         //m[v]++;
    //         return;
    //     }
    //     if(k<0) return;
    //     v.push_back(a[i]);
    //     fun(a,n,k-a[i],v,ans,i+1);
    //     v.pop_back();
    //     fun(a,n,k,v,ans,i+1);
        
    // }
    // vector<vector<int>> CombinationSum2(vector<int> a,int n,int k)
    // {
    //     //code here
    //   // unordered_map<vector<int>,int>m;
    //     set<vector<int>>ans;
    //   // int s=0;
    //     vector<int>v;
    //     sort(a.begin(),a.end());
    //     fun(a,n,k,v,ans,0);
    //     vector<vector<int>>p;
    //     for(auto i:ans)
    //     {
    //         p.push_back(i);
    //     }
    //     return p;
    // }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends