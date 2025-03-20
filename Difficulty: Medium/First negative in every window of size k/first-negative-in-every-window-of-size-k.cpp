//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
        vector<int> ans;
        deque<int> dq;
        int n = arr.size();
        
        // First window calculation:
        for(int i=0;i<k;i++)
        {
            if(arr[i]<0)
              dq.push_back(i);
        }
        if(dq.empty()==true)
          ans.push_back(0);
        else
          ans.push_back(arr[dq.front()]);
        
        // Moving the sliding window :
        for(int i=k;i<n;i++)
        {
            int add_in = i;
            int rem_in = i-k;
            
            if(!dq.empty() && dq.front() == rem_in)
              dq.pop_front();
            if(arr[add_in]<0)
              dq.push_back(add_in);
              
            if(dq.empty()==true)
              ans.push_back(0);
            else
              ans.push_back(arr[dq.front()]);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.FirstNegativeInteger(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends