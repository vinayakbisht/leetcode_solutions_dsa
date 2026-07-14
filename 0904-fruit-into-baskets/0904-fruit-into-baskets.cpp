class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxFruits = 0;
        unordered_map<int, int> basket;
        int l = 0;

        for(int r=0; r<fruits.size(); r++){
            basket[fruits[r]]++;

            while(basket.size() > 2){
                basket[fruits[l]]--;
                if(basket[fruits[l]] == 0){
                    basket.erase(fruits[l]);
                }
                l++;
            }
            maxFruits = max(maxFruits, r-l+1);
        }
        return maxFruits;
    }
};