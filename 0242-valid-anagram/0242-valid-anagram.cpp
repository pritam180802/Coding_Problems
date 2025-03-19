class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>map;

        for(int i=0;i<s.length();i++)
        {
            map[s[i]]++;
        }
        for(int j=0;j<t.length();j++)
        {
            if(map.find(t[j])!=map.end()) 
            {
                map[t[j]]--;
                if(map[t[j]]==0)
                  map.erase(t[j]);
            }
            else return false;
        }
        if(map.size()>0) return false;
        return true;
    }
};