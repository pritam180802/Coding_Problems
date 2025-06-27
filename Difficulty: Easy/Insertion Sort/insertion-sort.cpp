class Solution {
  public:
    // Please change the array in-place
    void insertionSort(vector<int>& arr) {
        // code here
        int size = arr.size();
        for(int i=1;i<size;i++){
            for(int j=i-1;j>=0;j--){
                if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
                else 
                break;
            }
        }
    }
};