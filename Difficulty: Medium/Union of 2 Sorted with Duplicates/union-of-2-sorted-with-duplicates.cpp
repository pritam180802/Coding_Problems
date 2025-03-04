//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        set<int>s;
        int p=0,q=0;
        
        while(p!=a.size() && q!=b.size()){
            if(a[p]<=b[q])
            s.insert(a[p++]);
            else
            s.insert(b[q++]);
        }
        
        // Insert remaining elements from a
        while (p < a.size())
        s.insert(a[p++]);
        
        // Insert remaining elements from b
        while (q < b.size())
        s.insert(b[q++]);
        
        vector<int> ans(s.begin(), s.end());
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a, b;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.findUnion(a, b);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends