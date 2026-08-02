class Solution {
public:
    bool isValidPalindrome(string &s, int i, int j){

        while(i<j){
         if(s[i] != s[j]){
            return false;
         }
         i++;
         j--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        int maxLen = INT_MIN;
        int sp = 0;

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){

                if(isValidPalindrome(s,i,j)){
                    if(j-i+1 > maxLen){
                        maxLen = j-i+1;
                        sp = i;
                    }
                }

            }
        }

        return s.substr(sp, maxLen);
    }
};