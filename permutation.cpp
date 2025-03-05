#include<iostream>
#include<vector>
using namespace std;
void permute(int index,string input,vector<string>&ans){
    if(index == input.size()){
        ans.push_back(input);
        return;
    }
    for(int j=index;j<input.size();j++){
        swap(input[index],input[j]);
        permute(index+1,input,ans);
        swap(input[index],input[j]);
    }
}

int main(){
    string input;
    cout<<"Enter a string: ";
    cin>>input;
    vector<string> ans;
    permute(0,input,ans);
    for(auto ele: ans){
        cout<<ele<<" "<<endl;
    }
}