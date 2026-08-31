class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;

        for (int i = 0; i < nums.size(); i++) {

            // If current index cannot be reached
            if (i > farthest) {
                return false;
            }

            farthest = max(farthest, i + nums[i]);

            // Last index is reachable
            if (farthest >= nums.size() - 1) {
                return true;
            }
        }

        return true;
    }
};