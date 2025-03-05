#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;

    int *arr=new int[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];

    // Prefix_sum: 
    int *pre=new int[n];
    for(int i=0;i<n;i++){
        if(i==0)
        pre[i]=arr[i];
        else
        pre[i]=pre[i-1]+arr[i];
    }

    int Q;
    cin>>Q;
    while(Q--){
        int a,b;
        cin>>a>>b;
        if(a-1>=0)
        cout<<pre[b]-pre[a-1]<<endl;
        else if(a==0)
        cout<<pre[b]<<endl;
    }
}