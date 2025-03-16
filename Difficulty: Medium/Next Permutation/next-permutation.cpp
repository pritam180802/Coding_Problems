//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        int breakpoint = -1;
        
        // Finding Breakpoint
        for(int i=n-2;i>=0;i--)
        {
           if(arr[i]<arr[i+1])
           {
               breakpoint = i;
               break;
           }
        }
        // Checking whether there is any breakpoint or not!!!
        if(breakpoint == -1)
        {
            reverse(arr.begin(),arr.end()); // If there is no breakpoint
            return;
        }
        //If the breakpoint found !!!
        int j;
        for(j=n-1;j>breakpoint;j--)
        {
            if(arr[j]>arr[breakpoint])
            break;
        }
        swap(arr[breakpoint],arr[j]);
        sort(arr.begin()+breakpoint+1,arr.end());
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
        Solution ob;
        int n = arr.size();
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends