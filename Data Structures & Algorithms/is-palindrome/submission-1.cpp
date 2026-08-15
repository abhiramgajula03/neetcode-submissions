class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.length();
        int j=n-1;
        int i=0;
        while(i<j){
            if(isalnum(s[j]) && isalnum(s[i])){
                 if(tolower(s[i])!=tolower(s[j])){
                      return false;
                   }
                   i++;
                   j--;
                }
                
            
            else if(!isalnum(s[j])){
                j--;
            }
            else{
                i++;
            }
        }
        return true;
    }
};
