#User function Template for python3
class Solution:
   def isValid(self,s):
        #code here
        a=s.split('.')
        if(len(a)!=4):
            return (0)
        #print(a)
        #return 1
        for i in a:
            n=len(i)
            #print(eval(i[::-1])%10)
            if(len(i)==0 or (i.isdigit())==False):
                return 0
            if(len(i)!=1 and i[::-1][-1]=='0'):
                return 0
            if(eval(i)<0  or eval(i)>255):
                return 0
        else:
            return 1

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(0, t):
        s = input()
        ob = Solution()
        if (ob.isValid(s)):
            print("true")
        else:
            print("false")

# } Driver Code Ends