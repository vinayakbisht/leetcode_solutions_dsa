class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";

        unordered_map<char, int> mpp;
        for(int i=0; i<t.size(); i++){    // store freq. of t's char.
            mpp[t[i]]++;
        }

        int minLen = INT_MAX;
        int countRequired = t.size();
        int i=0; int start_i = -1;

        for(int j=0; j<s.size(); j++){
            if(mpp[s[j]] > 0) countRequired--;
            
            mpp[s[j]]--;
            while(countRequired == 0){    // start shrinking
                if(j-i+1 < minLen){
                    minLen = j-i+1;
                    start_i = i;
                }
                if(++mpp[s[i]] > 0) countRequired++;
                i++;
            }
        }
        if(start_i == -1) return "";
        
        return s.substr(start_i, minLen);
    }
};  