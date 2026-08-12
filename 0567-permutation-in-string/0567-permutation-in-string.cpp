class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> s1Hash(26,0);
        vector<int> s2Hash(26,0);

        for(int i=0; i<s1.size(); i++){
            s1Hash[s1[i] - 'a']++;
        }

        int l=0;
        for(int r=0; r<s2.size(); r++){

            s2Hash[s2[r] - 'a']++;

            if(r-l+1 == s1.size() ){
                if(s1Hash == s2Hash){
                    return true;
                }
                s2Hash[s2[l] - 'a']--;
                l++;
            }
        }
        return false;
    }
};