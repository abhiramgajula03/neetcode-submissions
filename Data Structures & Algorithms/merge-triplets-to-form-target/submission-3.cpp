class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {

        int n = triplets.size();

        int r1 = 0;
        int r2 = 0;
        int r3 = 0;

        for (int i = 0; i < n; i++) {

            // This triplet cannot be used
            if (triplets[i][0] > target[0] ||
                triplets[i][1] > target[1] ||
                triplets[i][2] > target[2]) {
                continue;
            }

            r1 = max(r1, triplets[i][0]);
            r2 = max(r2, triplets[i][1]);
            r3 = max(r3, triplets[i][2]);

            if (r1 == target[0] &&
                r2 == target[1] &&
                r3 == target[2]) {
                return true;
            }
        }

        return false;
    }
};