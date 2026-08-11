class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n=nums.size();
        map<int,int>freq;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        vector<pair<int,int>>ans;
        for(auto f:freq){
            ans.push_back({f.second,f.first});
        }
        vector<int>res;
        sort(ans.rbegin(),ans.rend());
        int i =0;
        while(k>0){
            res.push_back(ans[i].second);
            i++;
            k--;
        }
        return res;
    }
};
