class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        
        int n = words.size();

        vector<int>ans;

        vector<int>preSum(n+1,0);

        unordered_set<char>vowels = {'a','e','i','o','u'};

        for(int i=0; i<n; i++){
            preSum[i+1] = preSum[i];

            if(vowels.count(words[i].front()) && vowels.count(words[i].back())){
                preSum[i+1]++;
            }
        }

        for(auto &x: queries){
            int left = x[0], right = x[1];
            ans.push_back(preSum[right+1]-preSum[left]);
        }

        return ans;
    }
};
