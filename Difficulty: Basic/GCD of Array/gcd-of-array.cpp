//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int gcd(int n, vector<int> arr) {
        int gc = 0;
        for(int i=0;i<n;i++)
          gc = __gcd(gc,arr[i]);
        return gc;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.gcd(n, arr) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends