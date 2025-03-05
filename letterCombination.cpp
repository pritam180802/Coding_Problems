// 17. Letter Combinations of a Phone Number(Leetcode):  [Lecture : 6]

#include<iostream>
#include<vector>
using namespace std;

void Generate(int index,string input, string map[],string output,vector<string> &result){
    if(index == input.size()){
       result.push_back(output);
       return;
    }
    int x = input[index]-'0';   // Extraction of 2 from "234"
    string val = map[x];        // val ==> string corresponding to symbol 2 : "abc"
    if(val.size()==0)
        Generate(index+1,input, map,output,result);
    else{
        for(int i=0;i<val.size();i++){
            Generate(index+1,input,map,output+val[i],result);
        }
    }
}

int main(){
    string input;
    cout<<"Enter a string: ";
    cin>>input;
    string map[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> result;
    Generate(0,input,map,"",result);

    for(auto ele: result){
        cout<<ele<<endl;
    }
    return 0;
}
