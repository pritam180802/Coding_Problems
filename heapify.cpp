#include<iostream>
using namespace std;

void heapify(int CBT[],int n,int index){

    int left = 2*index + 1;
    int right = 2*index + 2;
    int largest = index;
    
    if(left<n && CBT[largest]<CBT[left])
    largest = left;

    if(right<n && CBT[largest]<CBT[right])
    largest = right;

    if(index != largest){
        swap(CBT[index],CBT[largest]);
        heapify(CBT,n,largest);
    }
}

// Function to build a max-heap:
void buildHeap(int arr[],int n){
    for(int i=(n/2)-1;i>=0;i--){
        heapify(arr,n,i);
    }
}

int main(){
    int CBT[]={10,20,30,40,50,60,70};
    int n = sizeof(CBT) / sizeof(CBT[0]);
    
    buildHeap(CBT,n);
    for(int i=0;i<n;i++){
        cout<<CBT[i]<<" ";
    }
}