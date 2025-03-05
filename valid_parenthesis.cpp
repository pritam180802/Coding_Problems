// Generate All Possible Valid Parenthesis Expression :

#include<iostream>
using namespace std;

void generate(string tillNow,int open_rem,int close_rem){
    if(open_rem == 0 && close_rem == 0){
        cout<<tillNow<<endl;
        return;
    }
    if(open_rem > 0)
    generate(tillNow + "(" , open_rem-1 , close_rem);
    if(close_rem>0 && close_rem>open_rem)
    generate(tillNow + ")" , open_rem , close_rem-1);
}

int main(){
    int num;
    cout<<"Enter a number: ";
    cin>>num;
    generate("",num,num);
}