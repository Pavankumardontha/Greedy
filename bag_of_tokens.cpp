int solve(vector<int>& tokens, int i, int current_power, int current_score, int n)
{
    if(i==n)
    return current_score;
    int ans1 = 0; // face-up
    int ans2 = 0; // face-down
    int ans3 = 0; // do not play the current token
    if(current_power>=tokens[i])
    ans1 = solve(tokens,i+1,current_power-tokens[i],current_score+1,n);
    if(current_score>=1)
    ans2 = solve(tokens,i+1,current_power+tokens[i],current_score-1,n);
    ans3 = solve(tokens,i+1,current_power,current_score,n);
    return max(ans1,max(ans2,ans3));
}

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) 
    {
        int max_score=0;
        int current_score=0;
        int current_power = power;
        /*
        sort the tokens array
        1) Lets say you start with a power p, consume (Face-up) all the initial tokens which have less values (since the array is sorted)
        untill the current power becomes 0.
        2) Once the current power becomes 0, face-down the values from the end since the larger values will be at the end to increase the 
        power and then continue the same
        */
        int n = tokens.size();
        sort(tokens.begin(),tokens.end());
        int i=0;
        int j=n-1;
        while(i<=j)
        {
            if(current_power>=tokens[i])
            {
                // FACE-UP
                current_score = current_score+1;
                max_score = max(max_score,current_score);
                current_power = current_power - tokens[i];
                i++;
            }
            else if(current_score>0)
            {
                // we should not have current_score as 0 to face-down a value
                // FACE-DOWN
                current_score = current_score-1;
                current_power = current_power + tokens[j];
                j--;
            }
            else
            {
                /*
                Here current score is 0 and current power is less than token[i]. since the token array is sorted, it implies the current power
                is less than all the available elements in the tokens array from range[i,n-1]
                So we cannot play face-up or face-down too. we need to break here
                */
                break;
            }
        }
        return max_score;
    }
};
