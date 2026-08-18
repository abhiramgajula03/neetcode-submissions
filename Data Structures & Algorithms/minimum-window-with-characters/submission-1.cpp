class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        map<char, int> mp;

        for (int i = 0; i < m; i++) {
            mp[t[i]]++;
        }

        int mini = INT_MAX;
        int start = -1;

        int cnt = 0;
        int left = 0;

        map<char, int> temp;

        for (int right = 0; right < n; right++) {

            // If current character is present in t
            if (mp.find(s[right]) != mp.end()) {

                temp[s[right]]++;

                // Count only required occurrences
                if (temp[s[right]] <= mp[s[right]]) {
                    cnt++;
                }
            }

            // Window contains all characters of t
            while (cnt == m) {

                // Update minimum window
                if (right - left + 1 < mini) {
                    mini = right - left + 1;
                    start = left;
                }

                // Remove left character
                if (mp.find(s[left]) != mp.end()) {

                    if (temp[s[left]] <= mp[s[left]]) {
                        cnt--;
                    }

                    temp[s[left]]--;
                }

                left++;
            }
        }

        if (start == -1) {
            return "";
        }

        return s.substr(start, mini);
    }
};