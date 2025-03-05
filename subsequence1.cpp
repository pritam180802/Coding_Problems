#include<iostream>
#include<string>
using namespace std;

int sub(string input,string output[]){
    if(input.size()==0){
        output[0] = "";
        return 1;
    }
    int smallsize = sub(input.substr(1),output);
    for(int i = 0;i<smallsize;i++)
        output[i+smallsize] = input[0] + output[i];
    return 2*smallsize;

} 

int main(){
    string input;
    cout<<"Enter a string: ";
    cin>>input;
    string *output = new string[100];
    int size = sub(input,output);
    for(int i = 0;i<size;i++){
        cout<<output[i]<<endl;
    }
}