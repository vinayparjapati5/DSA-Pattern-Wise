class Solution {
public:
    int bestClosingTime(string customers) {

        int n = customers.size();

        int maxscore = 0, score = 0, best_time = -1;

        for(int i=0; i<n; i++){
            if(customers[i]=='Y'){
                score++;
            }
            if(customers[i]=='N'){
                score--;
            }
            if(score>maxscore){
                maxscore = score;
                best_time = i;
            }
        }
        return best_time+1;
    }
};
