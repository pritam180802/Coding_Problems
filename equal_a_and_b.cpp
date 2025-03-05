#include<iostream>
using namespace std;

void generate(string tillNow,int a,int b){
    if(a == 0 && b == 0){
        cout<<tillNow<<endl;
        return;
    }
    if(a > 0)
    generate(tillNow + "a",a-1,b);
    if(b > 0)
    generate(tillNow + "b",a,b-1);
}

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    generate("",n,n);
}