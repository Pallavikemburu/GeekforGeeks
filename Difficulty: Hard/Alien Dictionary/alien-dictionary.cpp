//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    void dfs(int i,vector<int>a[],vector<int>&vis,stack<int>&q)
	{
	    vis[i]=1;
	    for(auto it:a[i])
	    {
	        if(vis[it]!=1) dfs(it,a,vis,q);
	    }
	    q.push(i);
	}
    string findOrder(string dict[], int n, int k) {
        //code here
        vector<int>adj[k];
        for(int i=0;i<n-1;i++)
        {
            string s1=dict[i];
            string s2=dict[i+1];
            int len=min(s1.size(),s2.size());
            for(int j=0;j<len;j++)
            {
                if(s1[j]!=s2[j])
                {
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
        vector<int>vis(k,0);
	    stack<int>q;
	    vector<int>ans;
	    for(int i=0;i<k;i++)
	    {
	        if(vis[i]!=1)
	        dfs(i,adj,vis,q);
	    }
	    string s="";
	    
	    while(!q.empty())
	    {
	        s+=q.top()+'a';
	        q.pop();
	    }
	    return s;
        /*int size=k;
        vector<int>in(size,0);
        //vector<int>ans;
        string ans="";
        for(int i=0;i<size;i++)
        {
            for(auto it:adj[i])
            {
                in[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<size;i++)
        {
            if(in[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            auto p=q.front();
            ans+=p;
            q.pop();
            for(auto k:adj[p])
            {
                in[k]--;
                if(in[k]==0)
                {
                    q.push(k);
                }
            }
        }
        return ans;*/
        
	
    }
};


//{ Driver Code Starts.
string order;

bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++)
            cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i])
                f = false;

        if (f)
            cout << 1;
        else
            cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends