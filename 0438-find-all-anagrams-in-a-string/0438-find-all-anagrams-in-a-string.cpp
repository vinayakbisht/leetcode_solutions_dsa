class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        if(s.size() < p.size()) return {};
        vector<int> pHash(26,0);
        vector<int> sHash(26,0);
        vector<int> ans;
        for(int i=0; i<p.size(); i++){
            pHash[p[i] - 'a']++;            
        };

        int l=0;

        for(int r=0; r<s.size(); r++){
            sHash[s[r] - 'a']++;

            if(r-l+1 == p.size()){   //window
                if(pHash == sHash){
                  ans.push_back(l);
                }
              sHash[s[l] - 'a']--;
              l++;
            }       
        }
        return ans;
    }
};