class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mpp;
        int minLen = INT_MAX;
        int countRequired = t.size();

        for(int i=0; i<t.size(); i++){
            mpp[t[i]]++;
        }

        int i=0;
        int startI = -1;

        for(int j=0; j<s.size(); j++){
           
            if(mpp[s[j]] > 0){
                countRequired--;
            }
            mpp[s[j]]--;

            while(countRequired == 0){
                if(j-i+1 < minLen){
                    minLen = j-i+1;
                    startI = i;
                }
                if(++mpp[s[i]] > 0) countRequired++;
                i++;
            }

        }

        if(startI == -1){
            return "";
        }
        
        return s.substr(startI, minLen);
    }
};  