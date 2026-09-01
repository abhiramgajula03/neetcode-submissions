class Solution {
public:
    bool checkValidString(string s) {
        int n=s.length();
        int i=0;
        int open=0,close=0;
        while(i<n){
            if(s[i]=='('){
                open++;
                close++;
            }
            else if(s[i]==')'){
                open--;
                close--;
            }
            else{
                open--;
                close++;
            }
            if(close<0){
                return false;
            }
            open=max(0,open);
            i++;
        }
        return open==0;
    }
};
