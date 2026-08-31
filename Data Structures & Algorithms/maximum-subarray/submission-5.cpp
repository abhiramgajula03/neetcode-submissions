class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int maxi = INT_MIN;
        int sum = 0;

        int start = 0;
        int anstart = 0;
        int ansend = 0;

        for(int i = 0; i < n; i++) {

            if(sum == 0) {
                start = i;
            }

            sum += nums[i];

            if(sum > maxi) {
                maxi = sum;
                anstart = start;
                ansend = i;
            }

            if(sum < 0) {
                sum = 0;
            }
        }

        return maxi;
    }
};