#include<iostream>;
#include<vector>;
using namespace std;

void power(int index,int n,int arr[],vector<int> curr,vector<vector<int>> &ans){
    if(index == n){
        ans.push_back(curr);
        return;
    }
    // power(index+1,n,arr,curr,ans);
    // curr.push_back(arr[index]);
    // power(index+1,n,arr,curr,ans);

    // With backtracking : 

    curr.push_back(arr[index]);
    power(index+1,n,arr,curr,ans);
    curr.pop_back();
    power(index+1,n,arr,curr,ans);
}

int main(){
    int size;
    cout<<"Enter the size: ";
    cin>>size;
    int *arr = new int[size];
    for(int i=0;i<size;i++)
    cin>>arr[i];

    vector<int> current;
    vector<vector<int>> ans;
    power(0,size,arr,current,ans);

    for(auto vec: ans){      // printing All answers
        cout<<"[ ";            
        for(auto ele: vec){
            cout<<ele<<" ";
        }
        cout<<"]"<<endl;
    }
}