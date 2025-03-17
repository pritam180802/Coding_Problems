//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        
        // The problem starts from n=3
        if(n<3)
          return 0;
          
        // When n>=3
        int sum = 0;
        int pre[n];
        int post[n];
        pre[0]=arr[0];
        post[n-1]=arr[n-1];
        
        // Calculating pre:
        for(int i=1;i<n;i++)
          pre[i] = max(pre[i-1],arr[i]);
          
        // Calculating post:
        for(int j=n-2;j>=0;j--)
          post[j] = max(post[j+1],arr[j]);
          
        // Water calculation:
        for(int k=1;k<=n-2;k++)
          sum += min(pre[k],post[k]) - arr[k];
        return sum;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends