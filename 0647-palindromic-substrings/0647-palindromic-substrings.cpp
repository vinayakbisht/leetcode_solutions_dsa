class Solution {
public:
    int isPalindrome(string &s, int i, int j){
         int count = 0;
        while(i >= 0 && j <s.size() && s[i] == s[j]){
            count++;
            i--; 
            j++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int n =s.size();
        int count = 0 ;

        for(int i=0; i<n; i++){
           
           count += isPalindrome(s,i,i);
           count += isPalindrome(s,i,i+1);
        }
        return count;
    }
};