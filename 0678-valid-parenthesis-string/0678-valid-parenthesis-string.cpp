class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0, maxOpen = 0;
        for(auto it: s){
            if(it=='('){
                minOpen++;
                maxOpen++;
            }
            else if(it==')'){
                minOpen--;
                maxOpen--;
            }
            else{
                minOpen--;
                maxOpen++;
            }
            if(maxOpen<0)return false;
            minOpen = max(0,minOpen);
        }
        return minOpen==0;
    }
};