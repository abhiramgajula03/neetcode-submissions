class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int i = 0, j = 0;
        int maxi = 0;
        int maxfreq = 0;

        map<char, int> mp;

        while (j < n) {
            mp[s[j]]++;

            maxfreq = max(maxfreq, mp[s[j]]);

            int len = j - i + 1;
            int replace = len - maxfreq;

            while (replace > k) {
                mp[s[i]]--;
                i++;

                len = j - i + 1;
                replace = len - maxfreq;
            }

            maxi = max(maxi, j - i + 1);

            j++;
        }

        return maxi;
    }
};