// Print all the subsequences: 
#include<iostream>
using namespace std;

void sub(string str,string tillNow){
    if(str.size()==0){
        cout<<tillNow<<endl;
        return;
    }
    sub(str.substr(1), tillNow + str[0]);
    sub(str.substr(1), tillNow );
}

int main(){
    string input;
    cout<<"Enter a string: ";
    cin>>input;
    sub(input,"");
}