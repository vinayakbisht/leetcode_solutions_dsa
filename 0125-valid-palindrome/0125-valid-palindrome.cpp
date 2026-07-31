class Solution {
public:
    bool isPalindrome(string s) {

        int i=0, j=s.size()-1;

        for(char &ch : s){
            ch = tolower(ch);
        }
        
        while(i<j){
            
            if( !isalnum(s[i]) ){
                i++;
                continue;
            }
            if( !isalnum(s[j]) ){
                j--;
                continue;
            }

            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
    return true;
    }
};