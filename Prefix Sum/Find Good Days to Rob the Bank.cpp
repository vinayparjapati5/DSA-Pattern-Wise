class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();

        vector<int>ans;

        vector<int>nonInc(n);

        // left to right (if value dec increase count else make zero)
        for(int i=1; i<n; i++){
            if(security[i]>security[i-1]){
                nonInc[i] = 0;
            }
            else{
                nonInc[i] = nonInc[i-1]+1;
            }
        }

        //similar logic from right to left

        vector<int>nonDec(n);

        for(int i=n-2; i>=0; i--){
            if(security[i]>security[i+1]){
                nonDec[i] = 0;
            }
            else{
                nonDec[i] = nonDec[i+1]+1;
            }
        }

        for(int i = time; i<n-time; i++){

            if(nonDec[i]>=time && nonInc[i]>=time){
                ans.push_back(i);
            }

        }

        return ans;
        


    }
};
