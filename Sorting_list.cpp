#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool comp(pair<int,int>x,pair<int,int>y){
    if(x>y)
    return true;
    return false;
}
int main(){
    int n;
    cout<<"Enter the length: ";
    cin>>n;
    vector<pair<int,int>>v(n);
    cout<<"Enter the values: "<<endl;
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    for(int p=0;p<n;p++){
        for(int q=p+1;q<n;q++){
            if(comp(v[p],v[q]))
            swap(v[p],v[q]);
        }
    }
    for(int j=0;j<n;j++){
        cout<<v[j].first<<" "<<v[j].second<<endl;
    }
}