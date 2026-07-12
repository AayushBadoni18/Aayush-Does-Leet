/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void solve(ListNode* head, stack<int>&st, vector<int>&res){
        if(head->next){
            solve(head->next, st, res);
        }
        while(!st.empty() && st.top()<=head->val){
            st.pop();
        }
        if(st.empty())res.push_back(0);
        else res.push_back(st.top());
        st.push(head->val);
    }
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>res;
        stack<int>st;
        if(!head)return res;
        if(!head->next)return{0};
        solve(head,st, res);
        reverse(res.begin(),res.end());
        return res;
    }
};