//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        void lps(string &p,vector<int>&v)
        {
            v[0]=0;
            int i=1,l=0;
            while(i<p.size())
            {
                if(p[i]==p[l])
                {
                    l++;
                    v[i]=l;
                    i++;
                }
                else
                {
                    if(l==0)
                    {
                        v[i]=l;
                        i++;
                    }
                    else
                    {
                        l=v[l-1];
                    }
                }
            }
        }
        vector <int> search(string p, string s)
        {
            
            if(p.size()>s.size()) return {-1};
            vector<int>v(p.size());
            v[0]=0;
            lps(p,v);
            
            
           /* if(p.size()>s.size()) return {-1};
            int z=0;
            vector<int>v;
            int i=0,n=s.size()-1;
            while(z!=-1)
            {
                z=s.find(p,i+z,n);
                v.push_back(z);
            }
            return v;
            */
            
           /* vector<int>LPS(p.size());
            LPS[0]=0;
            vector<int>f(26,0);
            vector <int>ans;
            for(int i=0;i<p.size();i++)
            {
                if(f[p[i]-'a']>0)
                {
                    LPS[i]=LPS[i-1]+1;
                }
                else
                {
                    f[p[i]-'a']++;
                }
            }
           /* for(auto i:LPS)
            {
                cout<<i<<" ";
            } 
            */
            int i=0,j=0;
            vector <int>ans;
            while(i<s.size())
            {
                while(i<s.size() && j<p.size() && p[j]==s[i])
                {
                    i++;
                    j++;
                }
                if(j==p.size())
                {
                    
                    ans.push_back(i-p.size()+1);
                    j=v[j-1];
                }
                else if(i<s.size() && p[j]!=s[i])
                {
                    if(j==0)
                    {
                        i++;
                    }
                    else
                    {
                        j=v[j-1];
                    }
                }
            }
            if(ans.size()==0) return {-1};
            return ans;   
            
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends