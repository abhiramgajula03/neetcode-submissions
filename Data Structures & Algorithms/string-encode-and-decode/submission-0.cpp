class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";

        for (string str : strs) {
            s += to_string(str.size()) + "#" + str;
        }

        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;

        int i = 0;

        while (i < s.size()) {

            int j = i;

            // Find the '#'
            while (s[j] != '#') {
                j++;
            }

            // Get the length
            int len = stoi(s.substr(i, j - i));

            // Move after '#'
            j++;

            // Extract the string
            string str = s.substr(j, len);

            ans.push_back(str);

            // Move to the beginning of next encoded string
            i = j + len;
        }

        return ans;
    }
};