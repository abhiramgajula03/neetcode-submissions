class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int l = 0, r = 0;

        while (r < nums.size() - 1) {

            int farthest = 0;

            // Find the farthest position reachable
            // from the current range
            for (int i = l; i <= r; i++) {
                farthest = max(farthest, i + nums[i]);
            }

            // Move to the next range
            l = r + 1;
            r = farthest;

            jumps++;
        }

        return jumps;
    }
};