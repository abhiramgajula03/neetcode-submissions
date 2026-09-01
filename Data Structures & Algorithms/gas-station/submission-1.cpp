class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int n = gas.size();

        int start = 0;
        int tank = 0;
        int total = 0;

        for (int i = 0; i < n; i++) {

            int gain = gas[i] - cost[i];

            tank += gain;
            total += gain;

            // Current starting point cannot reach i+1
            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }

        if (total < 0)
            return -1;

        return start;
    }
};