class Solution {
public:
    vector<int> partitionLabels(string s) {

        int n = s.length();

        // Frequency of every character
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        vector<int> ans;

        int i = 0;

        while (i < n) {

            vector<int> seen(26, 0);

            char first = s[i];

            seen[first - 'a'] = 1;

            // We already consumed s[i]
            int cur = freq[first - 'a'] - 1;

            int j = i + 1;

            while (cur > 0) {

                char c = s[j];

                // New character enters the partition
                if (seen[c - 'a'] == 0) {

                    seen[c - 'a'] = 1;

                    // Add its remaining occurrences
                    // Current occurrence is already being consumed
                    cur += freq[c - 'a'] - 1;
                }

                // Character already belongs to partition
                else {
                    cur--;
                }

                j++;
            }

            // j is exclusive
            ans.push_back(j - i);

            i = j;
        }

        return ans;
    }
};