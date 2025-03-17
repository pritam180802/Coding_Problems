//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        int pre[n];
        int post[n];
        pre[0]=arr[0];
        post[n-1]=arr[n-1];
        
        //Calculating pre:
        for(int i=1;i<n;i++)
          pre[i] = pre[i-1] * arr[i];
          
        // Calculating post:
        for(int j=n-2;j>=0;j--)
          post[j] = post[j+1] * arr[j];
        
        // Calculating the required array:
        for(int k=0;k<n;k++)
        {
            if(k==0)
              ans.push_back(post[1]);
            else if(k==n-1)
              ans.push_back(pre[n-2]);
            else
              ans.push_back(pre[k-1]*post[k+1]);
        }
        return ans;
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
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends