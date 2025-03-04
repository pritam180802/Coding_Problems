//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void solve(int index,string s,vector<string> &answer,string temp){
        if(index==s.size()){
            answer.push_back(temp);
            return;
        }
        solve(index+1,s,answer,temp+s[index]);
        if(index!=s.size()-1)
        solve(index+1,s,answer,temp+s[index]+" ");
        
    }
    vector<string> permutation(string s) {
        // Code Here
        vector<string> ans;
        solve(0,s,ans,"");
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for (int i = 0; i < ans.size(); i++) {
            cout << "(" << ans[i] << ")";
        }
        cout << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends