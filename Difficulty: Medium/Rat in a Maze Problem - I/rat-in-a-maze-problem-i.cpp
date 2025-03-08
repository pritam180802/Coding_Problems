//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
  
    bool isDown(int row,int col,vector<vector<int>> &mat){
        if(row == mat.size()-1)
        return false;
        
        if(mat[row+1][col] == 1)
        return true;
    }
    bool isRight(int row,int col,vector<vector<int>> &mat){
        if(col == mat.size()-1)
        return false;
        
        if(mat[row][col+1] == 1)
        return true;
    }
    bool isLeft(int row,int col,vector<vector<int>> &mat){
        if(col == 0)
        return false;
        
        if(mat[row][col-1] == 1)
        return true;
    }
    bool isUp(int row,int col,vector<vector<int>> &mat){
        if(row == 0)
        return false;
        
        if(mat[row-1][col] == 1)
        return true;
    }
    
    void solve(int row,int col,vector<vector<int>> &mat,vector<string> &ans,string temp,vector<vector<int>> &visited){
        
        if(mat[row][col] == 0)
        return;
        
        if(row == mat.size()-1 && col == mat.size()-1){
            ans.push_back(temp);
            return;
        }
        
        if(isDown(row,col,mat)){
            if(visited[row+1][col] == 0){
                visited[row][col] = 1;
                temp.append("D");
                solve(row+1,col,mat,ans,temp,visited);
                visited[row][col] = 0;
                temp.pop_back();
            }
        }
        
        if(isRight(row,col,mat)){
            if(visited[row][col+1] == 0){
                visited[row][col] = 1;
                temp.append("R");
                solve(row,col+1,mat,ans,temp,visited);
                visited[row][col] = 0;
                temp.pop_back();
            }
        }
        
        if(isLeft(row,col,mat)){
            if(visited[row][col-1] == 0){
                visited[row][col] = 1;
                temp.append("L");
                solve(row,col-1,mat,ans,temp,visited);
                visited[row][col] = 0;
                temp.pop_back();
            }
            
        }
        
        if(isUp(row,col,mat)){
            if(visited[row-1][col] ==0){
                visited[row][col] = 1;
                temp.append("U");
                solve(row-1,col,mat,ans,temp,visited);
                visited[row][col] = 0;
                temp.pop_back();
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        vector<string> ans;
        int n = mat.size();
        vector<vector<int>>visited(n,vector<int>(n, 0));
        solve(0,0,mat,ans,"",visited);
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        vector<vector<int>> mat;
        string innerArray;
        bool isInsideArray = false;

        for (char c : input) {
            if (c == '[') {
                if (isInsideArray) {
                    innerArray.clear();
                }
                isInsideArray = true;
            } else if (c == ']') {
                if (isInsideArray && !innerArray.empty()) {
                    vector<int> row;
                    stringstream ss(innerArray);
                    int num;

                    while (ss >> num) {
                        row.push_back(num);
                        if (ss.peek() == ',')
                            ss.ignore();
                        while (isspace(ss.peek()))
                            ss.ignore();
                    }

                    mat.push_back(row);
                    innerArray.clear();
                }
                isInsideArray = false;
            } else if (isInsideArray) {
                if (!isspace(c)) {
                    innerArray += c;
                }
            }
        }

        Solution obj;
        vector<string> result = obj.findPath(mat);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << "[]";
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends