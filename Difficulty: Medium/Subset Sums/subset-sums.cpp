//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getSum(vector<int>arr){
        int sum = 0;
        for(auto ele:arr)
        sum += ele;
        return sum;
    }
    
    void solve(int index,vector<int>& arr,vector<int>& ans,vector<int> &temp){
        if(index == arr.size()){
            ans.push_back(getSum(temp));
            return;
           }
        solve(index+1,arr,ans,temp);
        temp.push_back(arr[index]);
        solve(index+1,arr,ans,temp);
        temp.pop_back();
        }
        
    
    vector<int> subsetSums(vector<int>& arr) {
        
        vector<int> ans;
        vector<int> temp;
        solve(0,arr,ans,temp);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after the integer input

    while (t--) {
        vector<int> inputArray;
        string inputLine;

        // Input format: first number n followed by the array elements
        getline(cin, inputLine);
        stringstream inputStream(inputLine);
        int num;
        while (inputStream >> num) {
            inputArray.push_back(num); // Read the array elements from input string
        }

        Solution solutionObject;
        vector<int> result = solutionObject.subsetSums(inputArray);
        sort(result.begin(), result.end());

        for (int i = 0; i < result.size(); i++) {
            if (i != 0)
                cout << " ";
            cout << result[i];
        }
        cout
            << endl
            << "~\n"; // Print results in list format with new line after each test case
    }

    return 0;
}

// } Driver Code Ends