//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string fun(string str,int &i)
    {
        string temp="";
        while(str[i]!='/' and i<str.size())
        {
            if(str[i]==',')
            {
                i+=2;
                return temp;
            }
            else
            {
                temp+=str[i];
                i++;
            }
        }
        i++;
        return temp;
    }
  
    string compareFrac(string str) {

        // Code here
        int i=0;
        string a=fun(str,i);
        string b=fun(str,i);
        string c=fun(str,i);
        string d=fun(str,i);
        float a1=stof(a);
        float b1=stof(b);
        float c1=stof(c);
        float d1=stof(d);
        float ans1=a1/b1;
        float ans2=c1/d1;
        if(ans1>ans2)
        {
            return a+"/"+b;
        }
        else if(ans2>ans1)
        {
            return c+"/"+d;
        }
        return "equal";
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends