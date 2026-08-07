class Solution {
public:
    int count = 0;

    void expand(string &s, int i, int j){
        while(i>=0 && j<s.size() && s[i] == s[j]){
            count++;
            i--;
            j++;
        }
    } 
    int countSubstrings(string s){
        int n = s.size();

        for(int i=0; i<n; i++){

            expand(s,i,i);
            expand(s,i,i+1); 
        }
        
        return count;
    }
};