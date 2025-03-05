#include<iostream>
using namespace std;
bool kyaswapkaru(int x,int y){          // Comparator Function
    if(x>y)
    return true;
    return false;
}
int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int *arr = new int[n];
    cout<<"Enter the element of the array: ";
    for(int x=0;x<n;x++){
        cin>>arr[x];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(kyaswapkaru(arr[i],arr[j]))
            swap(arr[i],arr[j]);
        }
    }

    for(int p=0;p<n;p++){
        cout<<arr[p]<<" ";
    }
}