class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            map<int, int> mp;

            for (int j = i + 1; j < n; j++) {
                int diff = -(nums[i] + nums[j]);

                if (mp.find(diff) != mp.end()) {
                    vector<int> vec;
                    vec.push_back(nums[i]);
                    vec.push_back(nums[j]);
                    vec.push_back(diff);

                    sort(vec.begin(), vec.end());

                    // Avoid duplicate triplets
                    if (find(ans.begin(), ans.end(), vec) == ans.end()) {
                        ans.push_back(vec);
                    }
                }

                mp[nums[j]] = j;
            }
        }

        return ans;
    }
};