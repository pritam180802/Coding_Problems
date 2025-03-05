#include<iostream>
using namespace std;

void sub(int index,string str,string tillNow){
    if(index == str.size()){
        cout<<tillNow<<endl;
        return;
    }
    sub(index+1,str,tillNow + str[index]);
    sub(index+1,str,tillNow );
}
int main(){
    string input ;
    cout<<"Enter a string: ";
    cin>>input ;
    sub(0,input,"");
}