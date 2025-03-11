class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            long ele=nums[i];
            long chair=ele-1;
            if(ele>0 && ele<=nums.size()){
                if(nums[chair]!=ele){
                    swap(nums[i],nums[chair]);
                    i--;
                }
            }
        }
        int index;
        for(index=0;index<nums.size();index++){
            if(nums[index]!=index+1)
            return index+1;
        }
        return nums.size()+1;
    }
};