class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int i=0, j=0;
        vector<int> sHash(256,0);

        while(j<s.size()){
            
            sHash[s[j]]++;
            while(sHash[s[j]] > 1){
                sHash[s[i]]--;
                i++;
            }
            
            maxLength = max(maxLength, j-i+1);
            j++;
        }
        return maxLength;
    }
};