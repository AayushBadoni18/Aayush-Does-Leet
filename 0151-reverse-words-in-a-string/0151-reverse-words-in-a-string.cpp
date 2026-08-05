class Solution {
public:
    string reverseWords(string s) {
        vector<string> str;

        for (int i = 0; i < s.size(); i++) {
            string temp = "";

            for (int j = i; j < s.size(); j++) {
                if (s[j] == ' ') {
                    if (temp.size()) {
                        str.push_back(temp);
                        i = j;
                        break;
                    }
                } else {
                    temp += s[j];
                }

                // Push the last word if we reached the end
                if (j == s.size() - 1 && temp.size()) {
                    str.push_back(temp);
                    i = j;
                }
            }
        }

        reverse(str.begin(), str.end());

        string ans = "";

        for (int i = 0; i < str.size(); i++) {
            ans += str[i];
            if (i != str.size() - 1)
                ans += " ";
        }

        return ans;
    }
};