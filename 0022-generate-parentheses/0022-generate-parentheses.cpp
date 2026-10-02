class Solution {
public:
    void generate(int n, int open, int close, string& curr, vector<string>& result) {
        if (curr.size() == 2 * n) {
            result.push_back(curr);
            return;
        }
        if (open < n) {
            curr.push_back('(');
            generate(n, open + 1, close, curr, result);
            curr.pop_back();  
        }

        if (close < open) {
            curr.push_back(')');
            generate(n, open, close + 1, curr, result);
            curr.pop_back(); 
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string curr;
        generate(n, 0, 0, curr, result);
        return result;
    }
};