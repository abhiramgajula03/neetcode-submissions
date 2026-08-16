class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        if (n > m)
            return false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        // Count characters of s1
        for (char c : s1) {
            freq1[c - 'a']++;
        }

        int i = 0;

        for (int j = 0; j < m; j++) {

            // Add current character
            freq2[s2[j] - 'a']++;

            // If window size is greater than s1
            if (j - i + 1 > n) {
                freq2[s2[i] - 'a']--;
                i++;
            }

            // Check window
            if (j - i + 1 == n) {
                if (freq1 == freq2) {
                    return true;
                }
            }
        }

        return false;
    }
};