class Solution {
public:
    int countSubstrings(string s){
        int n = s.size();

        vector<vector<bool>> t(n, vector<bool>(n,false));
        int count = 0;

        for(int len=1; len<=n; len++){
            for(int i=0; i+len-1<n; i++){
                
               int j = i+len-1;

               if(i==j){                  //1 length
                  t[i][j] = true;
                }
                else if(i+1 == j){      // 2 length
                   t[i][j] = (s[i] == s[j]);

                } else{
                    t[i][j] = (s[i] == s[j] && t[i+1][j-1] == true);
                }

                if(t[i][j] == true) count++;
            }
        }
        return count;
    }
};