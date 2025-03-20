//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        unordered_map<int,int>m; // <key,freq> pair
        vector<int> ans;
        int n = arr.size();
        
        // First window calculation:
        for(int i=0;i<k;i++)
        {
            m[arr[i]]++;
        }
        ans.push_back(m.size());
        
        // Moving the sliding window:
        for(int i=k;i<n;i++)
        {
            int rem = arr[i-k];
            int add = arr[i];
            
            if(m[rem]==1)
              m.erase(rem);
            else
              m[rem]--;
            
            m[add]++; // Adding the new element.
            ans.push_back(m.size());
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends