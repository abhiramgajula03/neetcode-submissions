class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int,int>mp;
        if(s.length()!=t.length()){
            return false;
        }
        for(int i=0;i<s.length();i++){
            mp[s[i]-'a']++;
        }
        for(int i=0;i<s.length();i++){
            if(mp.find(t[i]-'a')!=mp.end() && mp[t[i]-'a'] > 0){
                mp[t[i]-'a']--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
