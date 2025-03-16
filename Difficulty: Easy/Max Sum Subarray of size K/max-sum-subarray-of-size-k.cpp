//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maximumSumSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        int sum = 0;
        
        for(int i=0;i<k;i++)
            sum += arr[i];
        int max = sum;
        for(int j=1;j<=n-k;j++)  // Using Sliding window concept
        {
            sum -= arr[j-1];
            sum += arr[j+k-1];
            if(sum>max)
              max = sum;
        }
        return max;
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
        int ans = ob.maximumSumSubarray(arr, k);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends