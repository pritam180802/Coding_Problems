// Returning All The Subsequences: 

#include<iostream>
#include<vector>
using namespace std;

void sub(int index,string str,string tillNow,vector<string> &v){
    if(index == str.size()){
        v.push_back(tillNow);
        return;
    }
    sub(index+1,str,tillNow + str[index],v);
    sub(index+1,str,tillNow,v);
}
int main(){
    string input;
    cout<<"Enter a string: ";
    cin>>input;
    vector<string> v;
    sub(0,input,"",v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
}