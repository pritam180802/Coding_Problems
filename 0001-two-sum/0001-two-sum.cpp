class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>map;
        vector<int>v;
        for(int i=0;i<nums.size();i++)
        {
            int x = target-nums[i];
            if(map.find(x)!=map.end())
            {
              v.push_back(map[x]);
              v.push_back(i);
              return v;
            }
            else
              map[nums[i]] = i;
        }
       return {}; 
    }
};